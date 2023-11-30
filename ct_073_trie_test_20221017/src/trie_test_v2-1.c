/*
 * from: Data Structures
 *       The Trie Data Structure (Prefix Tree)
 *       Jacob Sorber
 *       https://www.youtube.com/watch?v=3CbFFVHQrk4
 */

/*
 * v2
 * add search and delete functions
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CHARS 256

typedef struct trienode {
	struct trienode *children[NUM_CHARS];
	bool terminal;
} trienode;

trienode *createnode();
bool trieinsert(trienode **root, char *signedtext);
void printtrie_rec(trienode *node, unsigned char *prefix, int length);
void printtrie(trienode *root);

// v2-1
bool searchtrie(trienode *root, char *signedtext);


/* main ------------------------------------------------ */
int main(int argc, char **argv) {
	trienode *root = NULL;

	trieinsert(&root, "KIT");
	trieinsert(&root, "CATTLE");
	trieinsert(&root, "KIN");
	trieinsert(&root, "CAT");
	trieinsert(&root, "HAPPY");
	printtrie(root);

	// test searchtrie() function
	
	// return 1 or 0:
	// printf("Search for CATTLE: %d\n", searchtrie(root, "CATTLE"));
	// printf("Search for CAT: %d\n", searchtrie(root, "CAT"));
	// printf("Search for KITTEN: %d\n", searchtrie(root, "KITTEN"));

	// return a note (string):
	printf("Search for CATTLE: %s\n", searchtrie(root, "CATTLE") ? "Found!" : "NOT found!");
	printf("Search for CAT: %s\n", searchtrie(root, "CAT") ? "Found!" : "NOT found!");
	printf("Search for KITTEN: %s\n", searchtrie(root, "KITTEN") ? "Found!" : "NOT found!");


	return 0;
} // end main


/* function definitions --------------------------------- */
trienode *createnode() {
	trienode *newnode = malloc(sizeof *newnode);

	// nulling all the children
	for (int i=0; i < NUM_CHARS; i++) {
		newnode->children[i] = NULL;
	}

	newnode->terminal = false;

	return newnode;
}


bool trieinsert(trienode **root, char *signedtext) {
	if (*root == NULL) {
		*root = createnode();
	}

	unsigned char *text = (unsigned char *)signedtext;
	trienode *tmp = *root;
	int length = strlen(signedtext);

	for (int i=0; i < length; i++) {
		if (tmp->children[text[i]] == NULL) {
			// create new node
			tmp->children[text[i]] = createnode();
		}
		tmp = tmp->children[text[i]];

	}
	if (tmp->terminal) {
		return false;
	} else {
		tmp->terminal = true;
		return true;
	}
}

void printtrie_rec(trienode *node, unsigned char *prefix, int length) {
	unsigned char newprefix[length + 2]; // aditional symbol + terminating \0 char
	memcpy(newprefix, prefix, length);
	newprefix[length+1] = 0;

	if (node->terminal) {
		printf("WORD: %s\n", prefix);
	}

	for (int i=0; i < NUM_CHARS; i++) {
		if (node->children[i] != NULL) {
			newprefix[length] = i;
			printtrie_rec(node->children[i], newprefix, length + 1);
		}
	}
}

void printtrie(trienode *root) {
	if (root == NULL) {
		printf("Trie empty!\n");
		return;
	}
	printtrie_rec(root, NULL, 0);
}

// v2-1
bool searchtrie(trienode *root, char *signedtext) {
	unsigned char *text = (unsigned char*)signedtext; // preventing negative values for lookup tables
	                                                  // that would cause weird memory problems!
	
	int length = strlen(signedtext);
	trienode *tmp = root;

	for (int i=0; i < length; i++) {
		if (tmp->children[text[i]] == NULL) {
			return false;
		}
		// tmp = tmp->children[text[i]];
		// or
		unsigned char c = text[i];
		tmp = tmp->children[c];
	}
	return tmp->terminal;

}

