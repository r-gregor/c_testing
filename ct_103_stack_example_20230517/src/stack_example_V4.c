#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_MAX_ELEMENTS 5

/**
 * from: Stack Data Structure And Operations | C Programming Example
 * https://www.youtube.com/watch?v=Flk5yrlx5Qo
 * Portfolio Courses
 * V4: - wrapper function test_if_empty converted from void to return a string
 *     - wrapper function test_if_full removed - not used
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
char *test_if_empty(Stack *stack);
void pop_test(Stack *stack, int *item);
void peek_test(Stack *stack, int *item);

/**
 * MAIN
 */
int main(int argc, char **argv) {

	Stack *stack;
	int peek_val = 0;
	int pop_val = 0;

#if 1
	// test 1
	printf("*** Creating the stack ***\n");
	stack = create_stack(STACK_MAX_ELEMENTS);
	if (stack == NULL) {
		printf("[ERROR]: Could not create stack\n");
		return 1;
	} else {
		printf("Stack of size %d elements successfuly created, %s", STACK_MAX_ELEMENTS, test_if_empty(stack));
	}

	printf("\n*** Push-ing (adding) items to the top of the stack ***\n");
	push(stack, 100);
	push(stack, 200);
	push(stack, 300);
	peek_test(stack, &peek_val);
	push(stack, 400);
	push(stack, 500);
	peek_test(stack, &peek_val);
	push(stack, 600);
	push(stack, 1000);
	peek_test(stack, &peek_val);

	printf("\n*** Pop-ing (removing) items from the top of the stack ***\n");
	int count = stack->size;
	for (int i = 0; i < count; i++) {
		pop_test(stack, &pop_val);

		if (is_empty(stack)) {
			printf(", stack is empty\n");
		} else {
			printf(", stack not empty\n");
		}

		if (stack->size == 1 || stack->size == 3 || stack->size == 0) {
			peek_test(stack, &peek_val);
		}
	}

	if (is_empty(stack)) {
		printf("Destroying stack, ");
		destroy_stack(stack);
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
} // END MAIN


/**
 * creating empty stack
 */
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

/**
 * destroying stack:
 *	- free-ing allocated memory
 *	- and NUL-ing the pointer to the stack
 */
void destroy_stack(Stack *stack){
	free(stack->collection);
	free(stack);
	stack->collection = NULL;
	stack = NULL;
	printf("stack successfuly destroyed\n");
}


/** is_empty */
bool is_empty(Stack *stack) {
	return stack->size == 0;
}

/** is_full */
bool is_full(Stack *stack) {
	return stack->size == stack->capacity;
}

/** pop */
bool pop(Stack *stack, int *item) {
	if (is_empty(stack)) return false;
	stack->size--;
	*item = stack->collection[stack->size];
	return true;
}

/** peek */
bool peek(Stack *stack, int *item) {
	if (is_empty(stack)) return false;
	*item = stack->collection[stack->size - 1];
	return true;
}

/** push */
bool push(Stack *stack, int item) {
	printf("Adding item '%d' to the stack, ", item);
	if (is_full(stack)) {
		printf("push failed, stack is full\n");
		return false;
	}
	stack->collection[stack->size] = item;
	stack->size += 1;
	printf("stack size: %d\n", stack->size);
	return true;
}

/**
 * wrapper function for pop-ping value
 * from the top of the stack
 */
void pop_test(Stack *stack, int *item) {
	bool try_pop = pop(stack, item);
	if (try_pop == false) {
		printf("[ERROR]: pop failed, stack is empty\n");
	} else {
		printf("Pop value: '%d', stack size: %d", *item, stack->size);
	}
}

/**
 * wrapper function for peek-ing value
 * on the top of the stack
 */
void peek_test(Stack *stack, int *item) {
	bool try_peek = peek(stack, item);
	if (try_peek == false) {
		printf("peek failed, stack is empty\n");
	} else {
		printf("Peek value: '%d', stack size: %d\n", *item, stack->size);
	}
}

/**
 * wrapper function for testing
 * if stack is empty
 */
char *test_if_empty(Stack *stack) {
	if (is_empty(stack)) {
		return "stack is empty\n";
	}
	return "stack is not empty\n";
}

