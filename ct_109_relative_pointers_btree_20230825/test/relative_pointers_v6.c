/*
 * relative_pointers_v6.c
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
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
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

#if 0
/* test main 1
 * rename original 'main' to 'main1'
 */
int main(void) {
	srand(time(0));
	// for (size_t i = 0; i < fruits_count; ++i) {
		// printf("%s\n", fruits[i]);
	for (size_t i = 0; i < 10; ++i) {
		printf("%s\n", fruits[rand()%fruits_count]);
	}
	return 0;
}
#endif

/*
 * Main =====================================================================================================
 */
int main(void) {
	srand(time(0));

#if 0
	/* TEST */
	Node *root = node_poll_alloc_with_text(&global_node_pool, "Hello, World");
	root->left =  node_poll_alloc_with_text(&global_node_pool, "Foo");
	root->right = node_poll_alloc_with_text(&global_node_pool, "Bar");
#endif

	Node *root = random_tree(&global_node_pool, 5);
	print_tree(stdout, root, 0);

	/* my addition */
	char *fname = "OUTPUT.txt";
	printf("---\nPrinting tree to file '%s' ... ", fname);
	FILE *fp = fopen(fname, "w");
	if (fp == NULL) {
		fprintf(stderr, "Could not print to file %s\n", fname);
		return 1;
	}
	print_tree(fp, root, 0);
	fclose(fp);
	printf("Done\n");


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

