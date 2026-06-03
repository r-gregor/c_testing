/*
 * struct_internal_offset_v1.c
 * from: c_struct-member-by-offset-multif_20230921.txt
 *
 * 20230919_01 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct{
	uint type;          // size  4 bytes, starts at offset  0
	char name[32];      // size 32 bytes, starts at offset  4
	float size;         // size  4 bytes, starts at offset 36
} MyStructType;

void display_struct();
void clr();

int main(void) {

	clr();
	display_struct();

	uint offset = (uint)(&((MyStructType *)NULL)->size);
	printf("Internal offset of 'float size' inside struct MyStructType is: %d\n", offset);
	printf("sizeof(MyStructType) = %ld\n", sizeof(MyStructType));

	return 0;
}

void display_struct() {
	printf("Declaration of struct:\n");
	printf("typedef struct{\n"
"	uint type;          // size  4 bytes, starts at offset  0\n"
"	char name[32];      // size 32 bytes, starts at offset  4\n"
"	float size;         // size  4 bytes, starts at offset 36\n"
"} MyStructType;\n");
	printf("---\n");
}

/* clear the screen */
void clr() {
	system("@cls||clear");
}

