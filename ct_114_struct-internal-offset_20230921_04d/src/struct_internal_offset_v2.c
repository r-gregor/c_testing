/*
 * struct_internal_offset_v2.c
 * from: c_struct-member-by-offset-multif_20230921.txt
 *
 * 20230919_01 (en)
 * 20230921_02 (en)
 * 20230921_03 (d)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  warning: cast from pointer to integer of different sizes
 *  sizeof(uint) == 4; sizeof(void *) == 8 !!
 *  sizeof(size_t) == 8 */
typedef unsigned int uint;

typedef struct{
	uint type;          // size  4 bytes, starts at offset  0
	char name[32];      // size 32 bytes, starts at offset  4
	float size;         // size  4 bytes, starts at offset 36
} MyStructType;

void display_struct();
void display_memory_addresses(MyStructType *str);
void clr();

int main(void) {

	clr();
	display_struct();

	MyStructType s1 = {0};
	MyStructType s2 = {0};
	MyStructType s3 = {0};

	 /* uint start = (uint)((MyStructType *)NULL); --> 0 (0x0) inner starting positon inside struct */
	uint offset = (uint)(&((MyStructType *)NULL)->size);
	printf("Internal offset of 'uint type' inside struct MyStructType is:   %4d\n", (uint)(&((MyStructType *)NULL)->type));
	printf("Internal offset of 'char name' inside struct MyStructType is:   %4d\n", (uint)(&((MyStructType *)NULL)->name));
	printf("Internal offset of 'float size' inside struct MyStructType is:  %4d\n", offset);
	printf("sizeof(MyStructType) = %ld\n", sizeof(MyStructType));

	printf("---\n");

	printf("Struct s1:\n");
	display_memory_addresses(&s1);

	printf("---\n");

	printf("Struct s2:\n");
	display_memory_addresses(&s2);

	printf("---\n");

	printf("Struct s3:\n");
	display_memory_addresses(&s3);



	return 0;
}

void display_struct() {
	printf("Declaration of struct:\n");
	printf("typedef struct{\n"
"	uint type;          // size  4 bytes, starts at offset     0\n"
"	char name[32];      // size 32 bytes, starts at offset     4\n"
"	float size;         // size  4 bytes, starts at offset    36\n"
"} MyStructType;\n");
	printf("---\n");
}

/* clear the screen */
void clr() {
	system("@cls||clear");
}

/*
 * %p is of type (void *): so all addresses and offsets must be casted to (void *)
 * to display correct results
 */
void display_memory_addresses(MyStructType *str) {
	/* inner offset fro beginning of struct to 'size' element */
	uint offset = (uint)(&((MyStructType *)NULL)->size);
	printf("Offset of element 'size':             %d (= %p)\n", offset, (void *) offset);
	printf("Memory address of struct:             %p\n", (void *)str);
	printf("Memory address of 'size':             %p\n", (void *)&(str->size));
	printf("-------------------------------------------------------\n");
	printf("Memory address of struct:             %p\n", (void *)str);
	printf("Address calculated from inner offset: %p\n", (void *)str + offset);
}

