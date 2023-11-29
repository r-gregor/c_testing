/*
 * array of int pointers
 * v1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ARR_SIZE 10

int main(int argc, char **argv) {

	printf("v1:\n");
	printf("Size of int pointer: %ld\n", sizeof(int *));

	int e1 = 100;
	int e2 = 200;
	int e3 = 300;
	int e5 = 500;
	int e8 = 800;


	int **arr = malloc(sizeof(int *) * ARR_SIZE);

	// v1
	// NULL out all array slots
	for (int j=0; j < ARR_SIZE; j++) {
		arr[j] = NULL;
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
		// skip array slot if NULL!
		// else: segfault!
		if (arr[i] == NULL) continue;
		printf("arr[%d] = %d\n", i, **(arr + i));
		printf("arr[%d] = %d\n", i, *(arr[i]));
		printf("---\n");
	}


	return 0;
}

