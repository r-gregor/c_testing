/*
 * from: This Data Structure could be used for Autocomplete
 *       https://www.youtube.com/watch?v=2fosrL7I7oc&t=3s
 *       Tsoding Daily: https://www.youtube.com/c/TsodingDaily
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ARRAY_LEN(xs) (sizeof(xs) / sizeof((xs)[0]))

typedef struct Node Node;

/* No need for a value, since the actual value
 * is the index of the position in an array.
 * If no values: there is no need to know if
 * node is a LEAF. It will just perform an
 * autocompletition.
 */
struct Node {
	Node *children[256]; // 256 ascii characters (just so many possible children)
	                     // it means 256 * 8 bytes/pointer = 2048 bytes (2 KB))
	                     // but memory is CHEAP!
};


// for custom allocator
#define NODE_POOL_CAP 1024
Node node_pool[NODE_POOL_CAP] = {0};
size_t node_pool_count = 0;

// custom allocator
Node *alloc_node(void) {
	assert(node_pool_count < NODE_POOL_CAP); // assert -> abort if expression is false
	return &node_pool[node_pool_count++];
}

void insert_text(Node *root, const char *text) {
	// if text is NULL or
	// if we try to enter ampty string, just return
	// this is a base case
	if (text == NULL || *text == '\0' ) {
		return;
	}

	// if it does NOT exist
	// make new node and try to insert
	// text that is one char shorter (text + 1)
	assert(root != NULL);

/*  this:
	if (root->children[*text] == NULL) {
		root->children[*text] = alloc_node();
	}
	insert_text(root->children[*text], text + 1);

	... gave the error:
trie.c: In function ‘insert_text’:
trie.c:51:28: error: array subscript has type ‘char’ [-Werror=char-subscripts]
   51 |         if (root->children[*text] == NULL) {
      |                            ^~~~~
trie.c:52:32: error: array subscript has type ‘char’ [-Werror=char-subscripts]
   52 |                 root->children[*text] = alloc_node();
      |                                ^~~~~
trie.c:54:36: error: array subscript has type ‘char’ [-Werror=char-subscripts]
   54 |         insert_text(root->children[*text], text + 1);
      |                                    ^~~~~

	so changed to this: (*text casted to size_t)
*/

	size_t index = (size_t) *text;
	if (root->children[index] == NULL) {
		root->children[index] = alloc_node();
	}
	insert_text(root->children[index], text + 1);
}

// for graphviz vizualizer
// dump dot root node and then all the edges for its children
void dump_dot(Node *root) {
	// get the index within the array
	size_t index = root - node_pool;
	printf("    Node%zu\n", index);

	// for (size_t i = 0; i < sizeof(root->children) / sizeof(root->children[0]); i++) {
	for (size_t i = 0; i < ARRAY_LEN(root->children); i++) {
		if (root->children[i] != NULL) {
			size_t child_index = root->children[i] - node_pool;
			printf("    Node%zu -> Node%zu\n", index, child_index);
			dump_dot(root->children[i]);
		}
	}

}


// main
int main(int argc, char **argv) {

	Node *root = alloc_node();
	insert_text(root, "hello");
	insert_text(root, "helium");
	
	// visualize
	printf("digraph Trie {\n");
	dump_dot(root);
	printf("}\n");

	return 0;
}

