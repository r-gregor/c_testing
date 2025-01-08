/*
 * from: What is an object pool, and how to create one in C?
 *       https://www.youtube.com/watch?v=CpgsQLSc7KY
 *       Jacob Sorber
 *       20250108 en
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Vector3 {
	int x, y, z;
} Vector3;

/* declare object pool */
/* to keep track of awailable objects */
typedef struct PoolObject {
	bool allocated;
	Vector3 obj;
} PoolObject;

#define NUM_OBJCTS 10
PoolObject object_pool[NUM_OBJCTS] = {0};

Vector3 *BorrowVector3(void) {
	for (int i=0; i < NUM_OBJCTS; i++) {
		if (object_pool[i].allocated == false) {
			object_pool[i].allocated = true;
			return &(object_pool[i].obj);
		}
	}
	return NULL; /* if all the object are borrowed */
}

/*
// v1: not fast due to for-looping over all objects
void ReturnVector3(Vector3 *v) {
	for (int i=0; i <  NUM_OBJCTS; i++) {
		if (&(object_pool[i].obj) == v) {
			assert(object_pool[i].allocated);
			object_pool[i].allocated = false;
			return;
		}
	}
	assert(false); // if reached to here, it is a bug: look into it!
}
*/


// v2: faster!
void ReturnVector3(Vector3 *v) {
	/* get index number from pointer position */
	unsigned int i = ((uintptr_t)v - (uintptr_t)object_pool) / sizeof(PoolObject);

	assert(&(object_pool[i].obj) == v);
	assert(object_pool[i].allocated);
	object_pool[i].allocated = false;
	return;
}


/* MAIN */
int main(void) {

	#if 0
	/* test1: malloc */
	for (int i=0; i < 15; i++) {
		Vector3 *v = malloc(sizeof(Vector3));
		printf("got vector @ addres %p\n", v);
		free(v);
	}
	#endif
	
	#if 0
	/* test2: BorrowVector3 */
	for (int i=0; i < 15; i++) {
		Vector3 *v = BorrowVector3();
		printf("got vector %2d @ address %p\n", i, v);
		ReturnVector3(v);
	}
	#endif
	
	/* test3: multiple BorrowVector3 */
	for (int i=0; i < 15; i++) {
		Vector3 *v1 = BorrowVector3();
		Vector3 *v2 = BorrowVector3();
		printf("got vectors %2d @ addresses %p and %p\n", i, v1, v2);
		ReturnVector3(v1);
		ReturnVector3(v2);
	}
	
	return 0;
} /* end main */

