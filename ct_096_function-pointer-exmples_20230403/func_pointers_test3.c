/* 20230404
 * func_pointers_test.c
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int64_t add(int64_t, int64_t);
int64_t sub(int64_t, int64_t);
void compute(int64_t (*fp)(int64_t,int64_t), int64_t a, int64_t b);

/**
 * MAIN
 */
int main(int argc, char **argv) {

	const char *str = "static";
	printf("str:         %p\n", str);
	printf("main:        %p\n", main);
	
	int64_t (*function_pointer)(int64_t,int64_t);
	function_pointer = &add;
	printf("fptr = &add: %p\n" ,function_pointer);

	function_pointer = add;
	printf("fptr =  add: %p\n" ,function_pointer);

	function_pointer = &sub;
	printf("fptr = &sub: %p\n" ,function_pointer);

	function_pointer = sub;
	printf("fptr =  sub: %p\n" ,function_pointer);

	printf("---\n"); // --------------------------------------------

	function_pointer = add;
	printf("12 + 10 = %ld\n", function_pointer(12,10));

	function_pointer = sub;
	printf("12 - 10 = %ld\n", function_pointer(12,10));

	printf("Add 12 and 12       - ");
	compute(add, 12, 12);

	printf("Subtract 120 and 12 - ");
	compute(sub, 120, 12);



	return 0;
} // end MAIN


int64_t add(int64_t a, int64_t b) {
	return a + b;
}

int64_t sub(int64_t a,int64_t b) {
	return a - b;
}

void compute(int64_t (*fp)(int64_t,int64_t), int64_t a, int64_t b) {
	printf("Result: %ld\n", fp(a, b));
}

