#include <stdio.h>
#include <string.h>
#include "isprime.h"


int main(int argc, char **argv) {

	bool all = true;
	size_t dvz;

	printf("Trying out the Euler's prime generating polynomial: n^2 + n + 41 = prime,\n");
	printf("for n = 0 - 150 Natuaral nubers (works for first 39):\n---\n");

	for (size_t i=0; i < 151; i++) {
		size_t e_num = i*i + i + 41;
		if (is_prime(e_num, &dvz)) {
			continue;
		} else {
			printf("Number %ld generated from %ld is NOT prime! (divizible by %ld)\n", e_num, i, dvz);
			all = false;
			// return -1;
		}
	}

	if (all) printf("All generated numbesr are primes!\n");


	return 0;
}

