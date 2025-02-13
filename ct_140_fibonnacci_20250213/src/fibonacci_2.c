/* fibonacci_2.c
 * fibonacci with while loop, without reczrsion!
 * 20250213 en
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate_fib(void *arg);
void fibswap(int *a, int *b);

int main(int argc, char **argv) {

	/* because 'char *' is 64bits long (8 bytes) and 'int' is 32bits long (4 bytes)
	 * and we cannot cast longer int into smaller one!
	 * Or we could use 'long' type for all integers
	 */
	long arg;

	if (2 == argc) {
		arg = atoi(argv[1]);
	}
	else {
		arg = 300;
	}

	printf("Displaying fibonacci numbers up to %ld:\n", arg);
	generate_fib((void *)arg);

	return 0;
}

void generate_fib(void *arg) {
	int MAX = (long)arg;
	int a = 0;
	int b = 1;

	while (a < MAX) {
		if (MAX < a + b) {
			printf("%d, ", a);
			fibswap(&a, &b);
			break;
		}
		else {
			printf("%d, ", a);
			fibswap(&a, &b);
		}

	}
	printf("%d\n", a);
}

/* make 'a' and 'b' take values of next pair in a sequence:
 * new 'b' becomes old 'a' + old 'b'
 * new 'a' becomes old 'b'
 */
void fibswap(int *a, int *b) {
	int c = *a + *b;
	*a = *b;
	*b = c;
}

