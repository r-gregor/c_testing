#ifndef _ISPRIME_H
#define _ISPRIME_H

#include <stdbool.h>

/**
 * is_prime() function takes two arguments:
 * 1 - size_t    n: a number to check if it is a prime,
 * 2 - size_t *dvz: pointer to integer that gets the value
 *                  of divizor if number is NOT prime.
 * Returns true if argument is prime number otherways false.
 */
bool is_prime(size_t n, size_t *dvz);

/* implementation */
bool is_prime(size_t n, size_t *dvz) {
	int i, flag = 0;
	// 0 and 1 are not prime numbers
	// change flag to 1 for non-prime number
	if (n == 0 || n == 1)
		flag = 1;

	for (i = 2; i <= n / 2; ++i) {

		// if n is divisible by i, then n is not prime
		// change flag to 1 for non-prime number
		// update value of dvz to divizor
		if (n % i == 0) {
			flag = 1;
			*dvz = i;
			break;
		}
	}

	// flag is 0 for prime numbers
	if (flag == 0)
		return true;

	return false;
}

#endif
