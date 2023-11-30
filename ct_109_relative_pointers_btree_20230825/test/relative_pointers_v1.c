/*
 * relative_pointers_v1.c
 * 20230825_01_en
 * ---
 * from: What is Relative Pointers? -- https://www.youtube.com/watch?v=_HGkhvpCbsk
 *       https://www.youtube.com/@TsodingDaily
 * ---
 *  v1: nodes left/right size_t offsets from region position (absolute pointer)
 *  If in struct left and right nodes use relative offset from containing memory region (node_poll array),
 *  array ould be dumped to a file and later retreived, and all relative offsets to the new memory
 *  location would work:
 *  result: SERIALIZEBILITY
 *  ---
 */
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	char text[32];
	size_t left;      // instead of Node *
	size_t right;     // instead of Node *
};

// stack based memory region - Arena
#define NODE_POOL_CAP 1024
Node node_poll[NODE_POOL_CAP];

/*
 * Main
 */
int main(void) {

	printf("filename: %s\n", __FILE__);

	return 0;
} // end Main

