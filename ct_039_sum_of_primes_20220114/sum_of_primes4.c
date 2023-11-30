#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PRIMES 100

int is_prime(int);



/* Updated 20220114 */

int main (int argc, char **argv) {

	int primes;
	if (argc != 2) {
		primes = NUM_PRIMES;
	} else {
		primes = atoi(argv[1]);
	}
	
	long sum = 0;

	printf("--- Calculating sum of primes from 0 to %d ---\n", primes);
	printf("\nPrimes added:\n");

	int count = 0;
	for (int i=1; i <= primes; i++) {
		if (is_prime(i)) {
			count++;
			if (count % 10 == 0) {
				printf("%8d\n", i);
			} else {
				printf("%8d", i);
			}
			sum += i;
		} else {
			continue;
		}
	}
	printf("\n");

	printf("\nSum of primes from 0 to %d: %ld\n", primes, sum);

	return 0;
}

int is_prime(int num) {

	if (num == 1) {
		return 0;
	}

	for (int i=2; i <= (int) sqrt((double) num); i++) {
		if (num % i == 0 && i != num) {
			return 0;
		}
	}
	return 1;
}

