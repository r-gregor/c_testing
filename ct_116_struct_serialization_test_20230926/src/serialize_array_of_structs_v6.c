/*
 * array_of_structs_serialization_v6.c
 * v6: offsetof() instead of fixed num in print_single_structs()
 *     #include <stddef.h>
 *     designated integer types uint64_t instead of size_t
 *
 * 20230926_01 (en)
 * 20230927_02 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h> // offsetof

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

/* 
 * char buffer[BUF_SIZE];
 *	// or
 *	// static ... inside main
 */

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

	printf("----------------------------------------------------------------\n");
	print_all_structs(buf);

	printf("----------------------------------------------------------------\n");
	// v4
	print_single_structs(buf, 3);

	printf("----------------------------------------------------------------\n");
	for (uint64_t i=4; i<8; i++) {
		print_single_structs(buf, i);
	}

	return 0;
} // end MAIN

/* add struct to buf memory region */
void add_struct(char *buf, char *name) {
	mystrct_t strct = {0};
	strct.count = strcts_global_count + 1;
	uint64_t next_offset = sizeof(mystrct_t) * strcts_global_count;

	if (next_offset >= BUF_SIZE) {
		printf("Buffer full!\n");
		return;
	}

	printf("Creating struct %ld with name: %s\n", strct.count, name);
	strcpy(strct.name, name);
	memcpy(buf + next_offset, &strct, sizeof(mystrct_t));

	strcts_global_count += 1;
}

/* print single struct info */
void print_single_structs(char *buf, uint64_t count) {
	if (count >= strcts_global_count) {
		fprintf(stderr, "buffer capacity owerflow!\n");
		return;
	}

	char *start = buf + count * sizeof(mystrct_t);
	char *cnt = start + (uint64_t)offsetof(mystrct_t, count);
	char *pointer = start + (uint64_t)offsetof(mystrct_t, name);
	printf("start: %p, cnt: %p, pointer: %p\n", start, cnt, pointer);
	printf("count: %ld\n", (uint64_t)*cnt);
	printf("name:  %s\n", pointer);
	printf("---\n");
}

/* print all structs given the strcts_global_count */
// v4
void print_all_structs(char *buf) {
	for (uint64_t count = 0; count < strcts_global_count; count++) {
		print_single_structs(buf, count);
	}
}

