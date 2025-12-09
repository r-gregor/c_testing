#ifndef OBJPOOL_H_
#define OBJPOOL_H_

#define NUM_OBJECTS 10000

typedef struct Vector3 {
	int x, y, z;
} Vector3;

Vector3 *BorrowVector3(void);
void ReturnVector3(Vector3 *v);

#endif

