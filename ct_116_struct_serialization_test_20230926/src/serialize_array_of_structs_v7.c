/*
 * array_of_structs_serialization_v7.c
 * v7: serialize buffer to external file.
 *     retreive_structs_from_file_v1.c (separate file)
 *
 * 20230926_01 (en)
 * 20230927_02 (en)
 * 20230928_03 (d)
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
void print_all_structs(char *buf);
void print_single_structs(char *buf, uint64_t count);


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
	print_all_structs(buf);
	print_single_structs(buf, 8);
	print_single_structs(buf, 3);
#endif
	
	/* new in v7 */
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

/* print single struct info */
void print_single_structs(char *buf, uint64_t count) {
	if (count > strcts_global_count) {
		fprintf(stderr, "Tried to print struct number %ld: ", count);
		fprintf(stderr, "buffer capacity owerflow!\n");
		printf("---\n");
		return;
	}

	char *start = buf + (count - 1)  * sizeof(mystrct_t);
	char *cnt =     start + (uint64_t)offsetof(mystrct_t, count);
	char *pointer = start + (uint64_t)offsetof(mystrct_t, name);
	printf("start: %p, cnt: %p, pointer: %p\n", start, cnt, pointer);
	printf("count: %ld\n", (uint64_t)*cnt);
	printf("name:  %s\n", pointer);
	printf("---\n");
}

/* print all structs given the strcts_global_count */
void print_all_structs(char *buf) {
	for (uint64_t count = 1; count <= strcts_global_count; count++) {
		print_single_structs(buf, count);
	}
}

