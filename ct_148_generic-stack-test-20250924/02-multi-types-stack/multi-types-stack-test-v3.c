/*
 * filename: mult-types-stack-test-v3.c
 * from: C Programming and Memory Management - Full Course --> Multiple Types
 *       https://www.youtube.com/watch?v=rJrd2QMVbGM
 *   at: 03:06:33 / 04:43:47
 * ---
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

stack_t *stack_new(size_t capacity);         /* test 1 */
void stack_push_multiple_types(stack_t *s);  /* test 2 */
void stack_free(stack_t *stack);             /* test 3 */

/* main */
int main(int argc, char **argv) {

	/* test 1 */
	int num_inserts = 3;
	printf("[INFO] test 1: testing stack creation\n");
	stack_t *s = stack_new(num_inserts);
	assert(s->capacity == 3);
	assert(s->count == 0);
	assert(s->data != NULL);
	printf("[INFO] test 1: OK\n---\n");

	/* test 2 */
	printf("[INFO] test 2: testing push to stack\n");
	stack_push_multiple_types(s);

	printf("[INFO] printing values from stack\n");
	printf("stack[%d] = %f\n", 0, *((float *) s->data[0]));
	printf("stack[%d] = %s\n", 1, (char *) s->data[1]);
	printf("stack[%d] = %s\n", 2, (char *) s->data[2]);
	printf("[INFO] test 2: OK\n---\n");

	/* test 3 */
	/* cleanup */
	printf("[INFO] test 3: freeing stack test\n");
	stack_free(s);

	if (s != NULL) { printf("  stack free-ed but NOT NULL-ed\n"); }
	printf("[INFO] test 3: OK\n\n");

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

/* function stack_free */
void stack_free(stack_t *stack) {
	if (stack == NULL) { return; }
	if (stack->data != NULL ) { /* or 'if (stack->data) {' ... */
		free(stack->data);
		// stack->data = NULL;
	}
	free(stack);
	// stack = NULL;
}

void stack_push_multiple_types(stack_t *s) {
	/* float */
	float *fptr = malloc(sizeof(float));
	*fptr = 3.14;
	stack_push(s, (void *)fptr);
	
	/* string from 'array[]' */
	char sent1[] = "Sentence 1 from an 'array[]'";
	size_t sent1_len = sizeof(sent1);
	char *string1 = malloc(sizeof(char) * sent1_len);
	strcpy(string1, sent1);
	stack_push(s, string1);

	/* string from 'char *' */
	char *sent2 = "Sentence 2 from 'char *'";
	size_t sent2_len = strlen(sent2) +1;
	char *string2 = malloc(sizeof(char) * sent2_len);
	strcpy(string2, sent2);
	stack_push(s, string2);
}

