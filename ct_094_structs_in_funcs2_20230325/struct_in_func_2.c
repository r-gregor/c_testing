/*
 * struct_in_func_2.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _container {
	int frst;
	int scnd;
	int thrd;
} Container;

void       fill_the_values(Container *C, int *a, int *b, int *c);  // pass   Container pointer as parameter to f
Container *fill_the_cnt1(int a, int b, int c);                     // return Container pointer
void       fill_the_cnt2(Container *C, int a, int b, int c);       // pass   Container pointer as parameter to f
Container  fill_the_cnt3(int a, int b, int c);                     // return Container struct

void       print_contents_of_cnt(Container *C);

int main(int argc, char **argv) {

	Container cnt1 = {.frst=2, .scnd=3, .thrd=4};

	int a;
	int b;
	int c;

	fill_the_values(&cnt1, &a, &b, &c);
	printf("a: %d\nb: %d\nc: %d\n", a, b, c);

	printf("---\n"); // ---
	
	Container *cnt2;
	cnt2 = fill_the_cnt1(15, 25, 35);
	print_contents_of_cnt(cnt2);
	free(cnt2);

	printf("---\n"); // ---

	Container cnt3;
	fill_the_cnt2(&cnt3, 100, 200, 300);
	print_contents_of_cnt(&cnt3);

	printf("---\n"); // ---

	Container *cnt4 = malloc(sizeof(Container));
	fill_the_cnt2(cnt4, 150, 250, 350);
	print_contents_of_cnt(cnt4);
	free(cnt4);

	printf("---\n"); // ---

	Container cnt5;
	cnt5 = fill_the_cnt3(1000, 2000, 3000);
	print_contents_of_cnt(&cnt5);

	return 0;
}

void fill_the_values(Container *C, int *a, int *b, int *c) {
	*a = C->frst;
	*b = C->scnd;
	*c = C->thrd;
}

/* return Container pointer
 * malloc inside function
 * must be freed from outside --
 * after run!
 */
Container *fill_the_cnt1(int a, int b, int c) {
	Container *result = malloc(sizeof(Container));
	result->frst = a;
	result->scnd = b;
	result->thrd = c;
	return result;
}

/* pass Container pointer as parameter to f
 * NO malloc, so no free() required
 * it receives a pointer to the struct
 */
void fill_the_cnt2(Container *C, int a, int b, int c) {
	C->frst = a;
	C->scnd = b;
	C->thrd = c;
}

/* return Container struct
 * NO malloc, so no free() required
 * it returns the struct initialized inside f
 */
Container fill_the_cnt3(int a, int b, int c) {
	Container C;
	C.frst = a;
	C.scnd = b;
	C.thrd = c;
	return C;
}

void print_contents_of_cnt(Container *C) {
	printf("First: %d\n", C->frst);
	printf("Second: %d\n", C->scnd);
	printf("Third: %d\n", C->thrd);
}

/*
 * memory leak check command:
 * $> valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s bin/<command>
 */

