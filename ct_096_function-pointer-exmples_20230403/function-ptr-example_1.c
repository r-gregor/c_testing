/*			20230403
 *			function-ptr-example_1.c
 * from:    Understanding and Using Function Pointers in C
 *          https://www.youtube.com/watch?v=axngwDJ79GY&t=4s
 *          ---
 *          https://www.youtube.com/@JacobSorber
 *
 */

// v1
#include <stdio.h>
#include <string.h>

typedef int (*operation_ptr)(int,int);

int add(int a,int b) {return a + b;}
int mult(int a,int b) {return a * b;}

// without typedef:
// int do_operation(int (*op)(int,int), int x, int y) {
int do_operation(operation_ptr op, int x, int y) {
	return op(x, y);
}

int main(int argc, char **argv) {

	int x = 5;
	int y = 10;
	printf("Addition:       %d\n", do_operation(add, x, y));
	printf("Multiplication: %d\n", do_operation(mult, x, y));

	return 0;
}

