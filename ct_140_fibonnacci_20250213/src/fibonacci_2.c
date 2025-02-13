/* fibonacci_2.c
 * fibonacci with while loop, without reczrsion!
 * 20250213 en
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate_fib(void *arg);

int main(int argc, char **argv) {
	int arg;

	if (2 == argc) {
		arg = atoi(argv[1]);
	}
	else {
		arg = 300;
	}

	printf("Displaying fibonacci numbers up to %d:\n", arg);
	generate_fib((void *)arg);

	return 0;
}

void generate_fib(void *arg) {
	int MAX = (int)arg;
	int a = 0;
	int b = 1;

	while (a < MAX) {
		if (MAX < a + b) {
			printf("%d, ", a);
			int c = a + b;
			a = b;
			b = c;
			break;
		}
		else {
			printf("%d, ", a);
			int c = a + b;
			a = b;
			b = c;
		}

	}
	printf("%d\n", a);
	// printf("%d\n", a);
}

