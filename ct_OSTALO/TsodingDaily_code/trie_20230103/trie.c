#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "fruits.h"

#define ARRAY_LEN(xs) (sizeof(xs) / sizeof((xs)[0]))

typedef struct Node Node;

struct Node {
    bool end;
    // TODO: explore the idea of using dynamically growing hash table for Node.children
    // TODO: explore the idea of using indices within the `node_pool` array instead of huge word size pointers.
    // on x86_64 they are literally 8 bytes!
    Node *children[256];
};

// TODO: serialize/deserialize the tree
#define NODE_POOL_CAP 1024
Node node_pool[NODE_POOL_CAP] = {0};
size_t node_pool_count = 0;

Node *alloc_node(void)
{
    assert(node_pool_count < NODE_POOL_CAP);
    return &node_pool[node_pool_count++];
}

// TODOOO: use loops instead of iterative recursion

void insert_text(Node *root, const char *text)
{
    assert(root != NULL);

    if (text == NULL || *text == '\0') {
        root->end = true;
        return;
    }

    size_t index = (size_t) *text;

    if (root->children[index] == NULL) {
        root->children[index] = alloc_node();
    }

    insert_text(root->children[index], text + 1);
}

// TODOO: you can actually dump the graphviz data by iterating linearly through the `node_pool` array
// TODOO: prettier style for graphviz output
// With compeling colors and shapes
void dump_dot(FILE *sink, Node *root)
{
    size_t index = root - node_pool;
    for (size_t i = 0; i < ARRAY_LEN(root->children); ++i) {
        if (root->children[i] != NULL) {
            size_t child_index = root->children[i] - node_pool;
            fprintf(sink, "    Node_%zu [label=\"%c\"]\n", child_index, (char) i);
            fprintf(sink, "    Node_%zu -> Node_%zu [label=\"%c\"]\n", index, child_index, (char) i);
            dump_dot(sink, root->children[i]);
        }
    }
}

void usage(FILE *sink, const char *program)
{
    fprintf(sink, "Usage: %s <SUBCOMMAND>\n", program);
    fprintf(sink, "SUBCOMMANDS:\n");
    fprintf(sink, "    dot                Dump the Trie into a Graphviz dot file.\n");
    fprintf(sink, "    complete <prefix>  Suggest prefix autocompletion based on the Trie.\n");
}

#define AC_BUFFER_CAP 1024
char ac_buffer[AC_BUFFER_CAP];
size_t ac_buffer_sz = 0;

void ac_buffer_push(char ch)
{
    assert(ac_buffer_sz < AC_BUFFER_CAP);
    ac_buffer[ac_buffer_sz++] = ch;
}

void ac_buffer_pop(void)
{
    assert(ac_buffer_sz > 0);
    ac_buffer_sz--;
}

Node *find_prefix(Node *root, const char *prefix)
{
    if (prefix == NULL || *prefix == '\0') {
        return root;
    }

    if (root == NULL) {
        return NULL;
    }

    ac_buffer_push(*prefix);
    return find_prefix(root->children[(size_t) *prefix], prefix + 1);
}

void print_autocompletion(FILE *sink, Node *root)
{
    if (root) {
        if (root->end) {
            fwrite(ac_buffer, ac_buffer_sz, 1, sink);
            fputc('\n', sink);
        }

        for (size_t i = 0; i < ARRAY_LEN(root->children); ++i) {
            if (root->children[i] != NULL) {
                ac_buffer_push((char) i);
                print_autocompletion(sink, root->children[i]);
                ac_buffer_pop();
            }
        }
    }
}

void cmd(char **argv)
{
    pid_t child = fork();

    if (child == 0) {
        if (execvp(argv[0], argv) < 0) {
            fprintf(stderr, "ERROR: could not execute the child: %s\n",
                    strerror(errno));
            exit(1);
        }
    } else if (child > 0) {
        int wstatus;
        if (wait(&wstatus) < 0) {
            fprintf(stderr, "ERROR: could not wait for the forked child: %s\n",
                    strerror(errno));
            exit(1);
        }
    } else {
        fprintf(stderr, "ERROR: could not fork a child: %s\n",
                strerror(errno));
        exit(1);
    }
}

bool is_safe(char ch)
{
    return strchr("@%+=:,./-_", ch) != NULL || isalnum(ch);
}

bool is_safe_str(const char *str)
{
    for (; *str; str++) {
        if (!is_safe(*str)) {
            return false;
        }
    }
    return true;
}

#define TMP_CAP (8 * 1024)
char tmp[TMP_CAP] = {0};
size_t tmp_size = 0;

char *tmp_end(void)
{
    return tmp + tmp_size;
}

char *tmp_alloc(size_t size)
{
    assert(tmp_size + size <= TMP_CAP);
    char *result = tmp_end();
    tmp_size += size;
    return result;
}

char *tmp_append_sized(const char *buffer, size_t buffer_sz)
{
    char *result = tmp_alloc(buffer_sz);
    return memcpy(result, buffer, buffer_sz);
}

char *tmp_append_cstr(const char *cstr)
{
    return tmp_append_sized(cstr, strlen(cstr));
}

void tmp_clean()
{
    tmp_size = 0;
}

void tmp_rewind(char *end)
{
    tmp_size = end - tmp;
}

const char *shell_escape(const char *str)
{
    if (str == NULL) {
        return "''";
    }

    if (is_safe_str(str)) {
        return str;
    }

    char *result = tmp_end();

    tmp_append_cstr("'");
    while (str) {
        char *end = strchr(str, '\'');
        if (end) {
            tmp_append_sized(str, end - str);
            tmp_append_cstr("'\"'\"'");
            str = end + 1;
        } else {
            tmp_append_cstr(str);
            str = NULL;
        }
    }
    tmp_append_cstr("'");
    tmp_append_sized("", 1);

    return result;
}

void echo_cmd(char **argv)
{
    char *end = tmp_end();
    printf("[CMD]");
    for (; *argv != NULL; argv++) {
        printf(" ");
        printf("%s", shell_escape(*argv));
    }
    printf("\n");
    tmp_rewind(end);
}

int main(int argc, char **argv)
{
    const char *program = *argv++;

    if (*argv == NULL) {
        usage(stderr, program);
        fprintf(stderr, "ERROR: no subcommand is provided\n");
        exit(1);
    }

    const char *subcommand = *argv++;

    Node *root = alloc_node();
    // TODO: unhardcode "training" data for the tree
    // Provide via a file or something
    for (size_t i = 0; i < fruits_count; ++i) {
        insert_text(root, fruits[i]);
    }

    if (strcmp(subcommand, "dot") == 0) {
        char *output_filepath = "trie.dot";

        printf("[INFO] Generating %s\n", output_filepath);

        FILE *f = fopen(output_filepath, "w");
        if (f == NULL) {
            fprintf(stderr, "ERROR: could not open file `%s`: %s",
                    output_filepath, strerror(errno));
            exit(1);
        }

        // TODOOO: `dot` should support [prefix] argument to inspect a specific prefix subtree
        fprintf(f, "digraph Trie {\n");
        fprintf(f, "    Node_%zu [label=root]\n", root - node_pool);
        dump_dot(f, root);
        fprintf(f, "}\n");

        fclose(f);

        char *dot_argv[] = {
            "dot",
            "-Tsvg",
            output_filepath,
            "-O",
            NULL,
        };

        echo_cmd(dot_argv);
        cmd(dot_argv);
    } else if (strcmp(subcommand, "complete") == 0) {
        if (*argv == NULL) {
            usage(stderr, program);
            fprintf(stderr, "ERROR: no prefix is provided\n");
            exit(1);
        }

        const char *prefix = *argv++;
        Node *subtree = find_prefix(root, prefix);
        if (subtree) {
            print_autocompletion(stdout, subtree);
        } else {
            fprintf(stderr, "No autocomplete suggestions found\n");
            exit(1);
        }
    } else {
        usage(stderr, program);
        fprintf(stderr, "ERROR: unknown subcommand `%s`\n", subcommand);
        exit(1);
    }

    // TODO: interactive ncurses based autocompletion demo that utilizes the prefix tree

    return 0;
}
