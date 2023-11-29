// v2
// added malloc error checking

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

void print_llist();

/*
 * release the malloc-ed memory for all nodes
 */
void release_all_nodes();

Node *head, *tail;
int num_of_elements = 0;

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
	release_all_nodes();

	return 0;
} // end main

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
	Node *item = head->next;
	printf("Number of elements: %d\n", num_of_elements);

	int count = num_of_elements;
	while(count > 1) {
		printf("%d, ", item->value);
		item = item->next;
		count--;
	}
	printf("%d\n", item->value);
}

void release_all_nodes() {
	int count = num_of_elements;
	while (count > 0) {
		Node *item = head->next;
		head->next = head->next->next;
		// test
		// printf("Releasing node: %d\n", item->value);
		free(item);
		item = NULL;
		count--;

	}
	free(head); head = NULL;
	free(tail); tail = NULL;
}

