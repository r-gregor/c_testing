/* fibonacci_2.c
 * fibonacci with while loop, without recursion!
 * 20250213 en
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ULONG_MAX_INT 4294967295

void generate_fib(void *arg);
void fibswap(unsigned long *a, unsigned long *b);

int main(int argc, char **argv) {

	/* because 'char *' is 64bits long (8 bytes) and 'int' is 32bits long (4 bytes)
	 * and we cannot cast longer int into smaller one!
	 * Or we could use 'long' type for all integers
	 */
	unsigned long arg;

	if (2 == argc) {
		arg = atoi(argv[1]);
		if (arg >= ULONG_MAX_INT) {
			fprintf(stderr, "Number TO big!\n");
			return -1;
		}
	}
	else {
		arg = 300;
	}

	printf("Displaying fibonacci numbers up to %ld:\n", arg);
	generate_fib((void *)arg);

	return 0;
}

void generate_fib(void *arg) {
	unsigned long MAX = (unsigned long)arg;
	unsigned long a = 0;
	unsigned long b = 1;

	while (a < MAX) {
		if (MAX < a + b) {
			printf("%ld, ", a);
			fibswap(&a, &b);
			break;
		}
		else {
			printf("%ld, ", a);
			fibswap(&a, &b);
		}

	}
	printf("%ld\n", a);
}

/* make 'a' and 'b' take values of next pair in a sequence:
 * new 'b' becomes old 'a' + old 'b'
 * new 'a' becomes old 'b'
 */
void fibswap(unsigned long *a, unsigned long *b) {
	unsigned long c = *a + *b;
	*a = *b;
	*b = c;
}

