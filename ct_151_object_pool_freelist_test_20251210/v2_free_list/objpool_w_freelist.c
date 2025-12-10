#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "objpool.h"

typedef struct PoolObject {
	struct PoolObject *next;
	Vector3 obj;
} PoolObject_t;

PoolObject_t objects_pool[NUM_OBJECTS] = {{0}};
PoolObject_t *freelist = NULL;

// runs automaticly before main!
__attribute__((constructor)) void InitializePool() {
	for (int i=0; i < NUM_OBJECTS - 1; i++) {
		objects_pool[i].next = &(objects_pool[i+1]);
	}
	freelist = objects_pool; // ... = objects_pool[0]; (same)
	objects_pool[NUM_OBJECTS - 1].next = NULL;
}


Vector3 *BorrowVector3(void) {
	if (freelist) {
		// store first element in freelist into temp var
		PoolObject_t *result = freelist;
		
		// remove vector from freelist
		freelist = freelist->next;

		// return result
		return &(result->obj);
	}
	return NULL; /* if all the object are borrowed */
}

void ReturnVector3(Vector3 *v) {
	/* get index number from pointer position */
	unsigned int i = ((uintptr_t)v - (uintptr_t)objects_pool) / sizeof(PoolObject_t);

	assert(&(objects_pool[i].obj) == v);

	// all object ar of the same size, so add the new one infron of the freelist:
	PoolObject_t *object_to_add = &(objects_pool[i]);
	object_to_add->next = freelist;
	freelist = object_to_add;

	return;
}

