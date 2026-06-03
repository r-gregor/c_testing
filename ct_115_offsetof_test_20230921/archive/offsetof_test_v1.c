/*
 * v1
 */
#include <stdio.h>
#include <string.h>
#include <stddef.h> // offsetof()


typedef struct Data {
	char name[256];
	size_t size;
	int age;
} Data;


int main(void) {

	printf("Offset of 'name': %ld\n", offsetof(Data, name));
	printf("Offset of 'size': %ld\n", offsetof(Data, size));
	printf("Offset of 'age':  %ld\n", offsetof(Data, age));
	printf("sizeof(struct Data): %ld\n", sizeof(Data));



	return 0;
}

