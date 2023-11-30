#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "isprime.h"

int main(int argc, char **argv) {

	size_t num;
	size_t dvz;

	if (argc != 2) {
		printf("No argument!\n");
		return -1;
	} else {
		num = atoi(argv[1]);
	}

	if (is_prime(num, &dvz)) {
		printf("Number %ld is prime\n", num);
	} else {
		printf("Number %ld is NOT prime, it is divisible by %ld\n", num, dvz);
	}

	return 0;
}

