/*
 * filename: generic-stack-test.c
 * from: C Programming and Memory Management - Full Course --> Low Level Stack
 *       https://www.youtube.com/watch?v=rJrd2QMVbGM
 *   at: 02:53:41 / 04:43:47
 * ---
 * 20250924 v1 en
 * 20250924 v2 en
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


/* main */
int main(int argc, char **argv) {

	/* test 1 */
	printf("[INFO] test 1: testing stack creation\n");
	size_t elnum = 3;
	stack_t *s = stack_new(elnum);
	assert(s->capacity == 3);
	assert(s->count == 0);
	assert(s->data != NULL);
	printf("[INFO] test 1: OK\n---\n");

	/* test 2 */
	printf("[INFO] test 2: testing push to stack\n");
	int obj1 = 44;
	int obj2 = 66;
	int obj3 = 88;

	/* v1
	stack_push(s, (void *) &obj1);
	stack_push(s, (void *) &obj2);
	stack_push(s, (void *) &obj3);
	*/

	/* v2 */
	stack_push(s, &obj1);
	stack_push(s, &obj2);
	stack_push(s, &obj3);

	/* when dereferencing 'void *' pointer, it must be cast to apropriate type: (int *) */
	for (int i = 0; i < elnum; i++) {
		printf("stack[%d] = %d (at address %p)\n", \
				i, \
				*((int *)(s->data[i])), \
				s->data[i]\
		);
	}
	printf("[INFO] test 2: OK\n---\n");

	/* test 3 */
	printf("[INFO] test 3: testing pop from stack\n");
	printf ("[INFO] stack count before pop: %ld\n", s->count);
	printf ("[INFO] trying to pop from stack ...\n");
	// void *result = stack_pop(s); /* v1 */
	int *result = stack_pop(s);     /* v2 */
	if (result == NULL) { return -1; }

	// printf ("[INFO] poped value: %d\n", *((int *)result));  /* v1 */
	printf ("[INFO] poped value: %d\n", *result);              /* v2 */

	printf ("[INFO] stack count after pop: %ld\n", s->count);
	printf("[INFO] test 3: OK\n---\n");

	/* test 4 */
	/* cleanup */
	printf("[INFO] test 4: freeing stack test\n");
	stack_free(s);
	if (s != NULL) { printf("Stack free-ed but NOT NULL-ed\n"); }
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

