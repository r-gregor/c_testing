/*          20230403
 *          function-ptr-example_2.c
 * from:    Why are function pointers useful?
 *          https://www.youtube.com/watch?v=ewBBRaF0oEA
 *          ---
 *          https://www.youtube.com/@CodeVault
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int a, int b) {return a + b;}
int prod(int a, int b) {return a * b;}

void shouldNotBeChanged(int (*operation)(int,int)) {
	srand(time(NULL));
	int a = rand() % 100;
	int b = rand() % 100;
	printf("The result of the operation between %d and %d is: %d\n",
			a, b, operation(a, b));
}

int main(int argc, char **argv) {

	shouldNotBeChanged(&sum);
	shouldNotBeChanged(&prod);

	// ---
	printf("---\n");
	
	// or:
	// define a function pointer fun
	int (*fun)(int,int);

	fun = &sum;
	shouldNotBeChanged(fun);

	fun = &prod;
	shouldNotBeChanged(fun);

	return 0;
}

