#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * from: Head vs Tail Recursion | C Programming Tutorial
 *       https://www.youtube.com/watch?v=l3qIbfuAhCw
 *       Portfolio Courses
 *
 * V1
 */

long sumBasicR(long n);
long sumHeadR(long n, long result);
long sumTailR(long n, long result);
long sumIterative(long n, long result);

/** MAIN */
int main(int argc, char **argv) {

	// Basic recursion
	long n = 5;
	printf("Basic recursion: sum of first %ld positive numbers: %ld\n", n, sumBasicR(n));

	// Head-recursion
	printf("Head-recursion:  sum of first %ld positive numbers: %ld\n", n, sumHeadR(n, 0));

	// Tail-recursion
	printf("Tail-recursion:  sum of first %ld positive numbers: %ld\n", n, sumTailR(n, 0));

	// Iterative func
	printf("Iterative func:  sum of first %ld positive numbers: %ld\n", n, sumIterative(n, 0));

	printf("Tail-recursion problem: sum of first 1000000 positive numbers: stack overflow (segmentation error)\n");

#if 0
	// Tail-recursion problem: large n = bn -> stack overflow -> segmentation error
	// CAN BE AVOIDED WITH COMPILATION OPTIMIZATION LEVEL 2: gcc -O2 ...
	long bn1 = 1000000;
	printf("Tail-recursion:  sum of first %ld positive numbers: %ld\n", bn1, sumTailR(bn1, 0));
#endif

	// Iterative func with large bn -> NO PROBLEM!
	long bn2 = 1000000;
	printf("Iterative func:  sum of first %ld positive numbers: %ld\n", bn2, sumIterative(bn2, 0));


	return 0;
} // END MAIN

/** basic recursion */
long sumBasicR(long n) {
	if (n == 0) return 0;         // base case
	else return n + sumBasicR(n - 1);
}

/** Head recursion */
long sumHeadR(long n, long result) {
	// order is important!
	if (n > 0) return sumHeadR(n - 1, result + n);
	else return result;           // base case
}

/** Tail recursion */
long sumTailR(long n, long result) {
	// order is important!
	if (n == 0) return result;
	else return sumTailR(n - 1, result + n);
}

/** Iterative sum function
 *  = modified Tail recursion function
 */
long sumIterative(long n, long result) {
	while (true) {
		if (n == 0) return result;
		result = result + n;
		n = n - 1;
	}
}

