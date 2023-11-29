/*
 * sas1_serialize_array_of_structs_v8.c
 * v8: add struct_count to print functions definition
 *     so they have same signature in both executables
 *     can be removed into separate header file.
 *
 * 20230926_01 (en)
 * 20230927_02 (en)
 * 20230928_03 (d)
 * 20230928_04 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit()
#include <stdint.h>
#include <stddef.h> // offsetof()

#define BUF_SIZE 640 // 10 x struct of size 64

/*
 * struct of size 8+8+48 = 64
 */
typedef struct mystrct {
	uint64_t offset;
	uint64_t count;
	char name[48];
} mystrct_t;

uint64_t strcts_global_count = 0;

void add_struct(char *buf, char *name);
void print_all_structs(char *buf, uint64_t structs_count);                         // v8
void print_single_structs(char *buf, uint64_t position, uint64_t structs_count);   // v8


/* MAIN */
int main(void) {
	static char buffer[BUF_SIZE];
	char *buf = (char *)&buffer;

	add_struct(buf, "Gregor Redelonghi");
	add_struct(buf, "Tadeja Mali Redelonghi");
	add_struct(buf, "Špela Redelonghi");
	add_struct(buf, "Zala Redelonghi");
	add_struct(buf, "Mark Redelonghi");
	add_struct(buf, "Sisi Redelonghi");
	add_struct(buf, "Berthold Sthrolzhenburger");

#if 0
	// test
	printf("---\n");
	print_all_structs(buf, strcts_global_count);
	print_single_structs(buf, 8, strcts_global_count);
	print_single_structs(buf, 3, strcts_global_count);
#endif
	
	char *fname = "structs_array.bin";
	FILE *fp = fopen(fname, "wb");

	if (fp == NULL) {
		fprintf(stderr, "Could NOT write to file: %s\n", fname);
		exit(1);
	}

	fwrite(buf, sizeof(mystrct_t), strcts_global_count, fp);
	printf("Array of struct serialized to %s\n", fname);

	fclose(fp);


	return 0;
} // end MAIN

/* add struct to buf memory region */
void add_struct(char *buf, char *name) {
	mystrct_t new_struct = {0};
	new_struct.count = strcts_global_count + 1;
	uint64_t next_offset = sizeof(mystrct_t) * strcts_global_count;

	if (next_offset >= BUF_SIZE) {
		printf("Buffer full!\n");
		return;
	}

	printf("Creating struct %ld with name: %s\n", new_struct.count, name);
	strcpy(new_struct.name, name);
	memcpy(buf + next_offset, &new_struct, sizeof(mystrct_t));

	strcts_global_count += 1;
}

/* from v7: print function remain just for testing */
/* print single struct info */
void print_single_structs(char *buf, uint64_t position, uint64_t structs_count) {
	if (position > strcts_global_count) {
		fprintf(stderr, "Tried to print struct number %ld: ", position);
		fprintf(stderr, "buffer capacity owerflow!\n");
		printf("---\n");
		return;
	}

	char *start = buf + (position - 1)  * sizeof(mystrct_t);
	char *cnt =     start + (uint64_t)offsetof(mystrct_t, count);
	char *pointer = start + (uint64_t)offsetof(mystrct_t, name);
	printf("start: %p, cnt: %p, pointer: %p\n", start, cnt, pointer);
	printf("count: %ld\n", (uint64_t)*cnt);
	printf("name:  %s\n", pointer);
	printf("---\n");
}

/* print all structs given the strcts_global_count */
void print_all_structs(char *buf, uint64_t structs_count) {
	for (uint64_t position = 1; position <= structs_count; position++) {
		print_single_structs(buf, position, structs_count);
	}
}

