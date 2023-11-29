#include <stdio.h>

#define NUM_PRIMES 18

int is_prime(int);

int main (int argc, char **argv) {
	
	int sum = 0;

	printf("--- Calculating sum of primes up to %d ---\n", NUM_PRIMES);

	for (int i=1; i < NUM_PRIMES; i++) {
		if (is_prime(i)) {
			printf("%d is prime --> adding ...\n", i);
			sum += i;
		} else {
			continue;
		}
	}

	printf("Sum of primes up to %d is: %d\n", NUM_PRIMES, sum);

	return 0;
}

int is_prime(int num) {

	if (num == 1) {
		return 0;
	}

	for (int i=2; i < num; i++) {
		if (num % i == 0 && i != num) {
			return 0;
		}
	}
	return 1;
}

