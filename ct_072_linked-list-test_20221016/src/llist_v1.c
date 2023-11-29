// v1
// linked-list without malloc error checking

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
void initialize_llist();

/*
 * add items at the start:
 * after the head and increase
 * the number of elements in list (without 
 * dummy head and start nodes)
 */
void add_to_start(int value);

void print_llist();

/*
 * release the malloc-ed memory
 */
void release_nodes();

Node *head, *tail;
int num_of_elements = 0;

/* main */
int main(int argc, char **argv) {

	initialize_llist();

	for (int N=1; N < 10; N++) {
		add_to_start(N * 1000);
	}

	print_llist();
	release_nodes();

	return 0;
} // end main

void initialize_llist() {
	// head = malloc(sizeof(Node));
	// tail = malloc(sizeof(Node));
	// or ...
	head = malloc(sizeof(*head));
	tail = malloc(sizeof(*tail));
	head->next = tail;
	tail->next = tail;
}

void add_to_start(int value) {
	Node *new = malloc(sizeof(Node));
	new->value = value;
	new->next = head->next;
	head->next = new;
	num_of_elements++;
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

void release_nodes() {
	int count = num_of_elements;
	while (count > 0) {
		Node *item = head->next;
		head->next = head->next->next;
		free(item);
		item = NULL;
		count--;

	}
	free(head); head = NULL;
	free(tail); tail = NULL;
}

