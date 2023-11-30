/*
 * from: Data Structures
 *       The Trie Data Structure (Prefix Tree)
 *       Jacob Sorber
 *       https://www.youtube.com/watch?v=3CbFFVHQrk4
 *       https://www.youtube.com/watch?v=NDfAYZCHstI&t=3s (part II)
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
trienode *deletestr_rec(trienode *node, unsigned char *text, bool *deleted);
bool deletestr(trienode **root, char *signedtext);
bool node_has_children(trienode *node);


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

	printf("---\n");
	// return a note (string):
	printf("Search for CATTLE: %s\n", searchtrie(root, "CATTLE") ? "Found!" : "NOT found!");
	printf("Search for CAT: %s\n", searchtrie(root, "CAT") ? "Found!" : "NOT found!");
	printf("Search for KITTEN: %s\n", searchtrie(root, "KITTEN") ? "Found!" : "NOT found!");

	printf("---\n");
	if (deletestr(&root, "KIN") == false) printf(" -- Oops! No such word!\n"); else printf("\n");
	if (deletestr(&root, "DOG") == false) printf(" -- Oops! No such word!\n"); else printf("\n");
	if (deletestr(&root, "CAT") == false) printf(" -- Oops! No such word!\n"); else printf("\n");

	printf("---\n");
	printtrie(root);



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

bool node_has_children(trienode *node) {
	if (node == NULL) return false;

	for (int i=0; 1 < NUM_CHARS; i++) {
		if (node->children[i] != NULL) {
			// has at least one child
			return true;
		}
	}
	return false;
}

trienode *deletestr_rec(trienode *node, unsigned char *text, bool *deleted) {
	if (node == NULL) return node;

	if (*text == '\0') {
		if (node->terminal) {
			node->terminal = false;
			*deleted = true;

			if (node_has_children(node) == false) {
				free(node);
				node = NULL;
			}
		}
		return node;
	}

	node->children[text[0]] = deletestr_rec(node->children[text[0]], text + 1, deleted);

	if (	*deleted &&
				node_has_children(node) == false &&
				node->terminal == false) {
		free(node);
		node = NULL;
	}
	return node;
}

bool deletestr(trienode **root, char *signedtext) {
	unsigned char *text = (unsigned char *)signedtext;
	bool result = false;

	printf("Deleting word: %s", text);
	
	// continue from: 8:06 of 16:45 (recursive Function -- https://www.youtube.com/watch?v=NDfAYZCHstI&t=3s)
	if (*root == NULL) return false;

	*root = deletestr_rec(*root, text, &result);
	return result;
}
