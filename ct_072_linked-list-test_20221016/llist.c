// v3
// freeing mallocs inside print function
// no need for extra release_all function

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

/*
 * initialize linked-list:
 * malloc head and tail
 */
int initialize_llist();

/*
 * add items at the start:
 * after the head and increase
 * the number of elements in list (without 
 * dummy head and start nodes)
 */
int add_to_start(int value);

/*
 * print llist elements and 
 * release memory of each element printed
 */
void print_llist();

// global variables declaration
Node *head, *tail;
int num_of_elements = 0;    // counter of llist elements

/* main */
int main(int argc, char **argv) {

	if (initialize_llist() < 0) {
		return -1;
	}

	for (int N=1; N < 10; N++) {
		if (add_to_start(N * 1000) < 0) {
			return -1;
		}
	}

	print_llist();

	return 0;
} // end main

// functions -------------------------------------

int initialize_llist() {
	// head = malloc(sizeof(Node));
	// tail = malloc(sizeof(Node));
	// or ...
	head = malloc(sizeof(*head));
	tail = malloc(sizeof(*tail));

	if (head == NULL || tail == NULL) {
		printf("Error initializing linked-list!\n");
		return -1;
	}

	head->next = tail;
	tail->next = tail;
	return 1;
}

int add_to_start(int value) {
	Node *new = malloc(sizeof(Node));

	if (new == NULL) {
		printf("Error allocating memory!\n");
		return -1;
	}

	new->value = value;
	new->next = head->next;
	head->next = new;
	num_of_elements++;

	return 1;
}

void print_llist() {
	printf("Number of elements: %d\n", num_of_elements);

	int count = num_of_elements;
	// print elements separated by space + comma up to last element
	// free node containing the element
	while(count > 1) {
		Node *item = head->next;
		head->next = head->next->next;
		printf("%d, ", item->value);
		free(item); item = NULL;
		count--;
	}
	// print last element without comma but with newline
	// free last node and both dummy nodes
	printf("%d\n", head->next->value);
	free(head->next); head->next = NULL;
	free(head); head = NULL;
	free(tail); tail = NULL;
}

