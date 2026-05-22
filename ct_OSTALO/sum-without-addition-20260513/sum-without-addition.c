/*
 * fname: sum-without-addition.c
 * from: https://www.youtube.com/shorts/p6RblqABDC4
 */
#include <stdio.h>
#include <string.h>

int sum(int a, int b);

int main(void) {

	int a = 3;
	int b = 4;
	printf("Sum of %d and %d is: %d\n", a, b, sum(a, b));

	return 0;
}


/*
 * sum without addition using recursive XOR and AND with shifting operation
 */
int sum(int a, int b) {
	return b == 0 ? a : sum(a^b, (unsigned int)(a&b) << 1);
}

