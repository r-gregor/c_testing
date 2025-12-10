/*
 * from: Making allocators and object pools faster using a free list
 *       https://www.youtube.com/watch?v=MxgnS9Lwv0k
 *       Jacob Sorber
 *       ---
 *       cotinues from last time: object_pool_test.c
 *       20251209 en
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include "objpool.h"

#define NUM_ROUNDS 100

int main(void) {

	srand(time(0));
	for (int i=0; i < NUM_ROUNDS; i++) {
		int numobjs = rand() % NUM_OBJECTS;
		Vector3 *vectors[numobjs]; //variable size array -- not to be used in production code!

		for (int j=0; j < numobjs; j++ ) {
			vectors[j] = BorrowVector3();
		}

		printf("round %2d -- got %d vectors\n", i, numobjs);

		for (int j=0; j < numobjs; j++ ) {
			ReturnVector3(vectors[j]);
		}
	}
	
	return 0;
} /* end main */

