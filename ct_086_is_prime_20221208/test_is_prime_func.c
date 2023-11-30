#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "isprime.h"

size_t get_positive_integer();

int main(int argc, char **argv) {

	size_t num;
	size_t dvz;

	if (argc == 2) {
		num = atoi(argv[1]);
	} else {
		num = get_positive_integer();
	}

	while(1) {
		if (is_prime(num, &dvz)) {
			printf("Number %ld is prime\n---\n", num);
			num = get_positive_integer();
		} else {
			printf("Number %ld is NOT prime, it is divisible by %ld\n---\n", num, dvz);
			break;
		}
	}

	return 0;
}

size_t get_positive_integer() {
	size_t input;
	printf("Enter new positive inrteger: ");
	scanf("%ld", &input);
	return input;
}

