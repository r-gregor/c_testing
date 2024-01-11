#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node * left, * right;
};

struct node * node1(int data) {
	struct node * tmp = (struct node * ) malloc(sizeof(struct node));
	tmp -> value = data;
	tmp -> left = tmp -> right = NULL;
	return tmp;
}

void print(struct node * root_node) // displaying the nodes!
{
	if (root_node != NULL) {
		print(root_node -> left);
		printf("%d \n", root_node -> value);
		print(root_node -> right);
	}
}

struct node * insert_node(struct node * node, int data) // inserting nodes!
{
	if (node == NULL) return node1(data);
	if (data < node -> value) {
		node -> left = insert_node(node -> left, data);
	} else if (data > node -> value) {
		node -> right = insert_node(node -> right, data);
	}
	return node;
}

int main() {
	printf("C implementation of Binary Search Tree!\n\n");
	struct node * parent = NULL;
	parent = insert_node(parent, 10);
	insert_node(parent, 4);
	insert_node(parent, 66);
	insert_node(parent, 45);
	insert_node(parent, 9);
	insert_node(parent, 7);
	print(parent);
	return 0;
}

