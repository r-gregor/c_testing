/*
 * array_of_structs_serialization_v2.c
 *
 * 20230926_01 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 640 // 10 x struct of size 64

/*
 * struct of size 8+8+48 = 64
 */
typedef struct mystrct {
	size_t offset;
	size_t count;
	char name[48];
} mystrct_t;

size_t strcts_global_count = 0;

void add_struct(char *buf, char *name);

/* MAIN */
int main(void) {
	char *buf = malloc(BUF_SIZE);

	add_struct(buf, "Gregor Redelonghi");
	add_struct(buf, "Tadeja Mali Redelonghi");
	add_struct(buf, "Špela Redelonghi");
	add_struct(buf, "Zala Redelonghi");
	add_struct(buf, "Mark Redelonghi");
	add_struct(buf, "Sisi Redelonghi");

	/*
	// test
	add_struct(buf, "Kr' EN Redelonghi"); // 7
	add_struct(buf, "Kr' EN Redelonghi"); // 8
	add_struct(buf, "Kr' EN Redelonghi"); // 9
	add_struct(buf, "Kr' EN Redelonghi"); // 10
	add_struct(buf, "Kr' EN Redelonghi"); // 11
	*/

	printf("----------------------------------------------------------------\n");

	// v2
	for (size_t count = 0; count < strcts_global_count; count++) {
		char *start = buf + count * sizeof(mystrct_t);
		char *cnt = start + (size_t)8;
		char *pointer = start + (size_t)16;
		printf("start: %p, cnt: %p, pointer: %p\n", start, cnt, pointer);
		printf("count: %ld\n", (size_t)*cnt);
		printf("name:  %s\n", pointer);
		printf("---\n");
	}


	// free(buf);

	return 0;
} // end MAIN

void add_struct(char *buf, char *name) {
	mystrct_t strct = {0};
	strct.count = strcts_global_count + 1;
	size_t next_offset = sizeof(mystrct_t) * strcts_global_count;

	// v2
	if (next_offset >= BUF_SIZE) {
		printf("Buffer full!\n");
		return;
	}

	// v2
	printf("Creating struct %ld with name: %s\n", strct.count, name);
	strcpy(strct.name, name);
	memcpy(buf + next_offset, &strct, sizeof(mystrct_t));

	strcts_global_count += 1;
}

