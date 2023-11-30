/*
 * relative_pointers_v3.c
 * 20230825_01_en
 * ---
 * from: What is Relative Pointers? -- https://www.youtube.com/watch?v=_HGkhvpCbsk
 *       https://www.youtube.com/@TsodingDaily
 * ---
 *  v2: nodes left/right relative offsets from absolute position of Node node itself
 *  If in struct left and right nodes use relative offset from Node variable,
 *  array could be dumped to a file and later retreived, and all relative offsets to the new memory
 *  location would work:
 *  result: SERIALIZEBILITY (not implemented yet)
 *  ---
 *  v3: combine functions node_poll_alloc and node_set_text into single function
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

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

/*
 * Main =====================================================================================================
 */
int main(void) {

#if 1
	/* TEST */
	printf("filename: %s\n", __FILE__);
	// printf("It Works!\n");
	CRT
#endif

	Node *root = node_poll_alloc_with_text(&global_node_pool, "Hello, Worldi");
	printf("root memory location: %p\n", root);




	return 0;
} // end Main ===============================================================================================

