#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * from: Stack Data Structure And Operations | C Programming Example
 * https://www.youtube.com/watch?v=Flk5yrlx5Qo
 * V1 -> 17:43 / 24:04 !!
 * Portfolio Courses
 */

typedef struct stack {
	int *collection;
	int capacity;
	int size;
} Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
bool pop(Stack *stack, int *item);
bool peek(Stack *stack, int *item);
bool push(Stack *stack, int item);

int main(int argc, char **argv) {

	Stack *stack;

#if 1
	// test 1
	stack = create_stack(5);
	if (stack == NULL) {
		fprintf(stderr, "[ERROR]: Could not create stack\n");
		return 1;
	} else {
		printf("[INFO]:  Stack successfuly created\n");
	}

	if (is_empty(stack)) {
		printf("[INFO]:  Stack is empty\n");
	}

	push(stack, 100);
	push(stack, 200);
	push(stack, 300);
	printf("[INFO]:  Stack size: %d\n", stack->size);


	push(stack, 400);
	push(stack, 500);
	printf("[INFO]:  Stack size: %d\n", stack->size);

	if (!push(stack, 600)) {
		fprintf(stderr, "[ERROR]: stack is full\n");
	}
	printf("[INFO]:  Stack size: %d\n", stack->size);

	bool try_push = push(stack, 1000);
	if(!try_push) fprintf(stderr, "[ERROR]: Push failed\n");

	destroy_stack(stack);

	printf("---\n");
#endif


#if 0
	// test 2: error creating empty stack
	stack = create_stack(0);
	if (stack == NULL) {
		fprintf(stderr, "[ERROR]: Could not create stack\n");
		return 1;
	} else {
		printf("[INFO]:  Stack successfuly created\n");
	}
#endif


	return 0;
}

Stack *create_stack(int capacity){

	if (capacity <= 0) return NULL;

	Stack *stack = malloc(sizeof(Stack));
	if (stack == NULL) return NULL;

	stack->collection = malloc(sizeof(int) * capacity);
	if (stack->collection == NULL) {
		free(stack);
		return NULL;
	}

	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}

void destroy_stack(Stack *stack){
	free(stack->collection);
	free(stack);
	stack->collection = NULL;
	stack = NULL;

	printf("[INFO]:  stack successfuly destroyed\n");
}

bool is_empty(Stack *stack) {
	return stack->size == 0;

}

bool is_full(Stack *stack) {
	return stack->size == stack->capacity;
}

bool pop(Stack *stack, int *item) {
	item  = NULL;
	stack = NULL;
	return false;
}

bool peek(Stack *stack, int *item) {
	item  = NULL;
	stack = NULL;
	return false;
}

bool push(Stack *stack, int item) {
	
	if (is_full(stack)) return false;

	stack->collection[stack->size] = item;
	printf("[INFO]:  Added item '%d' to the stack\n", item);
	stack->size += 1;

	return true;
}


