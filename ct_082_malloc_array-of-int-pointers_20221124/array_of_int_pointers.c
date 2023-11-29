/*
 * array of int pointers
 * v2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ARR_SIZE 10

int main(int argc, char **argv) {

	printf("v2:\n");
	printf("Size of (long *) pointer: %ld\n", sizeof(long *));

	long e00 = 9223372036854775807; // ((2^64)/2) - 1
	long e1 = 100;
	long e2 = 200;
	long e3 = 300;
	long e5 = 500;
	long e8 = 800;


	long **arr = malloc(sizeof(long *) * ARR_SIZE);

	// make all slots point to same initial value
	for (int j=0; j < ARR_SIZE; j++) {
		arr[j] = &e00;
	}
	
/*
 * 	arr[0] = &e1;
 * 	arr[1] = &e2;
 * 	arr[2] = &e3;
 * 	arr[4] = &e5;
 * 	arr[7] = &e8;
 */

 	*(arr + 0) = &e1;
 	*(arr + 1) = &e2;
 	*(arr + 2) = &e3;
 	*(arr + 4) = &e5;
 	*(arr + 7) = &e8;

	for (int i=0; i < ARR_SIZE; i++) {
		printf("arr[%d] = %ld\n", i, **(arr + i));
		printf("arr[%d] = %ld\n", i, *(arr[i]));
		printf("---\n");
	}


	return 0;
}

