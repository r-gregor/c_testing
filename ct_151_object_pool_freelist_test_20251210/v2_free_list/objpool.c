#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "objpool.h"

typedef struct PoolObject_t {
	bool allocated;
	Vector3 obj;
} PoolObject_t;

PoolObject_t objects_pool[NUM_OBJECTS] = {{0}};

Vector3 *BorrowVector3(void) {
	for (int i=0; i<NUM_OBJECTS; i++) {
		if (objects_pool[i].allocated == false) {
			objects_pool[i].allocated = true;
			return &(objects_pool[i].obj);
		}
	}
	return NULL; /* if all the object are borrowed */
}

void ReturnVector3(Vector3 *v) {
	/* get index number from pointer position */
	unsigned int i = ((uintptr_t)v - (uintptr_t)objects_pool) / sizeof(PoolObject_t);

	assert(&(objects_pool[i].obj) == v);
	assert(objects_pool[i].allocated);
	objects_pool[i].allocated = false;
	return;
}

