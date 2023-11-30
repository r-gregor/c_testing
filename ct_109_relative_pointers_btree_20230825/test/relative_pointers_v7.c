/*
 * relative_pointers_v7.c
 * 20230825_01_en
 * ---
 * from:   What is Relative Pointers? -- https://www.youtube.com/watch?v=_HGkhvpCbsk
 *         https://www.youtube.com/@TsodingDaily
 * fruits: https://github.com/tsoding/jim/examples/fruits.h
 * ---
 *  v2: nodes left/right relative offsets from absolute position of Node node itself
 *  If in struct left and right nodes use relative offset from Node variable,
 *  array could be dumped to a file and later retreived, and all relative offsets to the new memory
 *  location would work:
 *  result: SERIALIZEBILITY (not implemented yet)
 *  ---
 *  v3: combine functions node_poll_alloc and node_set_text into single function
 *  ---
 *  v4: print_tree() -- UNIMPLEMENTED ==> v5: implementation!
 *  ---
 *  v6: random_tree()
 *  all is done using ABSOLUTE pointers, so NO SERIALIZEBLIITY
 *  ---
 *  v7: save node_poll to file with fwrite (man fwrite) wich is especially suited to dump arrays into file
 *      fwrite returns the number of sucessfully written items (we can assert n == np->sz)
 *      check fruits.bin eith hexedit command (Linux)
 *
 *      load node_poll from file with fread!
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "./fruits.h"

#define CRT printf("---\n");

typedef struct Node Node;

struct Node {
	char text[32];
	Node *left;      // absolute pointers!
	Node *right;     // absolute pointers!
};

/* stack based memory region - Arena */
#define NODE_POOL_CAP 1024

typedef struct {
	size_t sz;       // tracking the amount of data in memory region
	Node nodes[NODE_POOL_CAP];
} Node_Pool;

/* global static allocation of Node_Pool memory region, end zero-initialize */
static Node_Pool global_node_pool = {0};

/* functions initializations */
Node *node_poll_alloc(Node_Pool *np);
void node_set_text(Node *node, const char *text_cstr);
Node *node_poll_alloc_with_text(Node_Pool *np, const char *text_cstr);
void print_tree(FILE *stream, Node *node, size_t level);
Node *random_tree(Node_Pool *np, size_t level);
void save_node_poll_to_file(Node_Pool *np, const char *file_path);
void load_node_poll_from_file(Node_Pool *np, char const *file_path);


#define FRUITS_BIN_PATH "fruits.bin"
#define OUTPUT_TXT_PATH "OUTPUT.txt"

#if 0
int main(void) {
	// after fruits.bin has bin created:
	// when build and run it segfaults !! -- 49:56 / 1:51:27
	// because we are using ABSOLUTE pointers!!
	load_node_poll_from_file(&global_node_pool, FRUITS_BIN_PATH);
	Node *root = &global_node_pool.nodes[0];
	print_tree(stdout, root, 0);

	return 0;
}
#endif

/*
 * Main =====================================================================================================
 */
int main(void) {
	srand(time(0));

	Node *root = random_tree(&global_node_pool, 5);
	print_tree(stdout, root, 0);
	save_node_poll_to_file(&global_node_pool, FRUITS_BIN_PATH);

#if 1
	/* my addition */
	printf("---\nPrinting tree to file '%s' ... ", OUTPUT_TXT_PATH);
	FILE *fp = fopen(OUTPUT_TXT_PATH, "w");
	if (fp == NULL) {
		fprintf(stderr, "Could not print to file %s\n", OUTPUT_TXT_PATH);
		return 1;
	}
	print_tree(fp, root, 0);
	fclose(fp);
	printf("Done\n");
#endif


	return 0;
} // end Main ===============================================================================================

// FUNCTIIONS DECLARATIONS

/* very simple linear (Arena) allocator */
Node *node_poll_alloc(Node_Pool *np) {
	assert(np->sz < NODE_POOL_CAP);

	/* an absolute pointer to last node in Node_Pool */
	Node *result = &np->nodes[np->sz];

	/* zero-initialize the node */
	memset(result, 0, sizeof(Node));
	np->sz += 1;

	return result;
}

/* insert text into node and truncate it if to big
 * text must be c-string = null-terminated!
 */
void node_set_text(Node *node, const char *text_cstr) {
	size_t n = strlen(text_cstr);

	/* if string is larger than sizeof(node->text[32]) - 1 (last char must be '\0')
	 * it must be truncated to that size
	 */
	if (n > sizeof(node->text) - 1) {
		n = sizeof(node->text) - 1;
	}

	memset(node->text, 0, sizeof(node->text)); // to make shure string will be null-terminated
	memcpy(node->text, text_cstr, n);
}

/* v3: combine node_poll_alloc and node_set_text into single function */
Node *node_poll_alloc_with_text(Node_Pool *np, const char *text_cstr) {
	Node *result = node_poll_alloc(np);
	node_set_text(result, text_cstr);
	return result;
}

/* print out tree to stream (stdout, file ...)
 * If printout to file, it needs FILE *fd - file descriptor
 * using fopen() ...
 */
void print_tree(FILE *stream, Node *node, size_t level) {
	char s[6] ;
	size_t i;
	for (i = 0; i < level; i++) fputs("  ", stream);
	sprintf(s, "%zu > ", i);
	fputs(s, stream);
	fputs(node->text, stream);
	fputc('\n', stream);
	if (node->left)  print_tree(stream, node->left,  level + 1);
	if (node->right) print_tree(stream, node->right, level + 1);
}

/* ORIGINAL -- only spaces for level indication ...
void print_tree(FILE *stream, Node *node, size_t level) {
	for (i = 0; i < level; i++) fputs("  ", stream);
	fputs(node->text, stream);
	fputc('\n', stream);
	if (node->left)  print_tree(stream, node->left,  level + 1);
	if (node->right) print_tree(stream, node->right, level + 1);
}
*/


/* generate random btree (binary tree) -- each node has two sub-nodes */
Node *random_tree(Node_Pool *np, size_t level) {
	if (level == 0) return NULL; // base case: no more sub-nodes
	Node *root = node_poll_alloc_with_text(np, fruits[rand()%fruits_count]);
	root->left  = random_tree(np, level -1); // recursion
	root->right = random_tree(np, level -1); // recursion
	return root;
}


/* dump node_poll array into file */
void save_node_poll_to_file(Node_Pool *np, const char *file_path) {
	FILE *out = fopen(file_path, "wb");
	if (out == NULL) {
		fprintf(stderr, "Could NOT write to file %s: %s\n", file_path, strerror(errno));
		exit(1);
	}
	size_t n = fwrite(np->nodes, sizeof(Node), np->sz, out);
	assert(n == np->sz);

	if(ferror(out)) {
		fprintf(stderr, "Could NOT write to file %s: %s\n", file_path, strerror(errno));
		exit(1);
	}
	fclose(out);
}


/* load contents of file into node_poll */
void load_node_poll_from_file(Node_Pool *np, char const *file_path) {
	FILE *out = fopen(file_path, "rb");

	if (out == NULL) {
		fprintf(stderr, "Could NOT read from file %s: %s\n", file_path, strerror(errno));
		exit(1);
	}

	fseek(out, 0, SEEK_END);
	long m = ftell(out); // size of file
	fseek(out, 0, SEEK_SET);

	assert(m % sizeof(Node) == 0);

	np->sz = m / sizeof(Node);
	assert(np->sz <= NODE_POOL_CAP);

	size_t n = fread(np->nodes, sizeof(Node), np->sz, out);
	assert(n == np->sz);

	if(ferror(out)) {
		fprintf(stderr, "Could NOT read from file %s: %s\n", file_path, strerror(errno));
		exit(1);
	}
	fclose(out);
}


