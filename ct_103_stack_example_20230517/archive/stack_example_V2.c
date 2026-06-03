#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_MAX_ELEMENTS 5

/**
 * from: Stack Data Structure And Operations | C Programming Example
 * https://www.youtube.com/watch?v=Flk5yrlx5Qo
 * V2
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
	int peek_val = 0;                               // V2
	int pop_val = 0;                                // V2

#if 1
	// test 1
	stack = create_stack(STACK_MAX_ELEMENTS);
	if (stack == NULL) {
		fprintf(stderr, "[ERROR]: Could not create stack\n");
		return 1;
	} else {
		printf("Stack of size %d elements successfuly created\n", STACK_MAX_ELEMENTS);
	}

	if (is_empty(stack)) {
		printf("Stack is empty\n");
	}

	push(stack, 100);
	push(stack, 200);
	push(stack, 300);
	printf("Stack size: %d\n", stack->size);
	peek(stack, &peek_val);                         // V2
	printf("Peek value: '%d'\n", peek_val);         // V2

	push(stack, 400);
	push(stack, 500);
	printf("Stack size: %d\n", stack->size);
	peek(stack, &peek_val);                         // V2
	printf("Peek value: '%d'\n", peek_val);         // V2

	if (!push(stack, 600)) {
		fprintf(stderr, "[ERROR]: Push failed. Stack is full\n");
	}
	printf("Stack size: %d\n", stack->size);

	bool try_push = push(stack, 1000);
	if(!try_push) fprintf(stderr, "[ERROR]: Push failed. Stack is full\n");

	// V2 ---
	int count = stack->size;
	for (int i = 0; i < count; i++) {
		pop(stack, &pop_val);
		printf("Pop value: '%d', stack size: %d", pop_val, stack->size);
		
		if (is_empty(stack)) {
			printf(", Stack is empty\n");
			bool try_pop = pop(stack, &pop_val);
			if (try_pop == false) {
				printf("[ERROR]: Pop failed. Stack is empty\n");
			}
			printf("Destroying stack ... ");
			destroy_stack(stack);
		} else {
			printf(", Stack not empty\n");
		}
	}

	

	printf("---\n");
#endif


#if 1
	// test 2: error creating empty stack
	stack = create_stack(0);
	if (stack == NULL) {
		fprintf(stderr, "[ERROR]: Could not create stack\n");
		return 1;
	} else {
		printf("Stack successfuly created\n");
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
	printf("stack successfuly destroyed\n");
}

bool is_empty(Stack *stack) {
	return stack->size == 0;

}

bool is_full(Stack *stack) {
	return stack->size == stack->capacity;
}

bool pop(Stack *stack, int *item) {
	if (is_empty(stack)) return false;
	stack->size--;
	*item = stack->collection[stack->size];

	return true;
}

bool peek(Stack *stack, int *item) {
	if (is_empty(stack)) return false;
	*item = stack->collection[stack->size - 1];
	return true;
}

bool push(Stack *stack, int item) {
	printf("Adding item '%d' to the stack\n", item);
	if (is_full(stack)) return false;
	stack->collection[stack->size] = item;
	stack->size += 1;
	return true;
}


