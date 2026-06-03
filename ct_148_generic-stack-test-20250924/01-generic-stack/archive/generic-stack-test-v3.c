/*
 * filename: generic-stack-test-v3.c
 * from: C Programming and Memory Management - Full Course --> Low Level Stack
 *       https://www.youtube.com/watch?v=rJrd2QMVbGM
 *   at: 02:53:41 / 04:43:47
 * ---
 * 20250924 v1 en
 * 20250924 v2 en
 * 20250924 v3 en
 * last: 20250924
 */
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Stack {
	size_t count;
	size_t capacity;
	void **data; /* array of (void *) pointers */
} stack_t;

stack_t *stack_new(size_t capacity);           /* test 1 */
void stack_push(stack_t *stack, void *obj);    /* test 2 */
void *stack_pop(stack_t *stack);               /* test 3 */
void stack_free(stack_t *stack);               /* test 4 */
long get_addr_diff(void *curr, void *prev);
void display_stack_elements(stack_t *stack);
void display_poped_value(stack_t *stack);


/* main */
int main(int argc, char **argv) {

	/* v3 */
	int nums[] = {11, 22, 33, 44, 55, 66, 77, 88, 99}; /* 9 elements */
	size_t nums_sz = sizeof(nums) / sizeof(nums[0]);

	/* test 1 */
	printf("[INFO] test 1: testing stack creation\n");
	stack_t *s = stack_new(nums_sz); /* v3 */
	assert(s->capacity == 9);        /* v3 */
	assert(s->count == 0);
	assert(s->data != NULL);
	printf("[INFO] test 1: OK\n---\n");

	/* test 2 */
	printf("[INFO] test 2: testing push to stack\n");

	/* v3 */

	for (int i = 0; i < nums_sz; i++) {
		stack_push(s, &nums[i]);
	}

	/* v3 */
	display_stack_elements(s);
	printf("[INFO] test 2: OK\n---\n");

	/* test 3 */
	printf("[INFO] test 3: testing pop from stack\n");
	printf("  stack count before pop-s: %ld\n", s->count);
	printf("  trying to pop from stack ...\n");
	// printf ("  poped value: %d\n", *((int *)stack_pop(s)));              /* v3 */
	int count = 4;
	while (count > 0) {
		display_poped_value(s);
		count--;
	}
	printf ("  stack count after pop-s: %ld\n", s->count);
	display_stack_elements(s);
	printf("[INFO] test 3: OK\n---\n");

	/* test 4 */
	/* cleanup */
	printf("[INFO] test 4: freeing stack test\n");
	stack_free(s);
	if (s != NULL) { printf("  stack free-ed but NOT NULL-ed\n"); }
	printf("[INFO] test 4: OK\n\n");

	return 0;
} /* END main */

/* ======================================================================= */

/* function: stack_new */
stack_t *stack_new(size_t capacity) {
	stack_t *s = malloc(sizeof(stack_t));
	if (s == NULL) { return NULL; }

	s->count = 0;
	s->capacity = capacity;

	s->data = malloc(sizeof(void *) * s->capacity);
	if (s->data == NULL) { return NULL; }

	return s;
}

/* function: stack_push */
void stack_push(stack_t *stack, void *obj) {
	if (stack->count == stack->capacity) {
		stack->capacity *= 2;
		stack->data = realloc(stack->data, sizeof(void *) * stack->capacity);
		if (stack->data == NULL) { return; }
	}
	stack->data[stack->count] = obj;
	stack->count++;

	return;
}

/* function stack_pop */
void *stack_pop(stack_t *stack) {
	if (stack->count == 0) { return NULL; }
	stack->count--;

	return stack->data[stack->count];
}

/* function stack_free */
void stack_free(stack_t *stack) {
	if (stack == NULL) { return; }
	if (stack->data != NULL ) { /* or 'if (stack->data) {' ... */
		free(stack->data);
		stack->data = NULL;
	}
	free(stack);
	stack = NULL;
}

long get_addr_diff(void *curr, void *prev) {
	return (long)curr - (long)prev;
}

void display_stack_elements(stack_t *stack) {
	int i = 0;
	printf("  stack[%d] = %d (at address %p), offset from previous: 0 bytes\n", \
			i, \
			/* when dereferencing 'void *' pointer, it must be cast to apropriate type: (int *) */
			*((int *)(stack->data[i])), \
			stack->data[i]\
	);

	for (int j = 1; j < stack->count; j++) {
		/* v3 */
		printf("  stack[%d] = %d (at address %p), offset from previous: %ld bytes\n", \
			j, \
			/* when dereferencing 'void *' pointer, it must be cast to apropriate type: (int *) */
			*((int *)(stack->data[j])), \
			stack->data[j], \
			get_addr_diff(stack->data[j], stack->data[j-1])
		);
	}
}

void display_poped_value(stack_t *stack) {
	int *result = stack_pop(stack);
	if (result == NULL) { return; }
	printf ("  pop-ed from stack: %d\n", *result);
}

