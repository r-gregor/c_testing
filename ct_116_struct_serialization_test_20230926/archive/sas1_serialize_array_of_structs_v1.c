/*
 * sas1_serialize_array_of_structs_v1.c
 *
 * 20230926_01 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * struct of size 8+8+48 = 64
 */
typedef struct mystrct {
	size_t offset;
	size_t count;
	char name[48];
} mystrct_t;

#define BUF_SIZE 640 // 10 x struct of size 64

size_t strcts_global_count = 0;

void add_struct(char *buf, char *name);

/* MAIN */
int main(void) {
	// static char buf[640]; // 10x struct of size 64
	char *buf = malloc(BUF_SIZE); // 10x struct of size 64

	add_struct(buf, "Gregor Redelonghi");
	add_struct(buf, "Tadeja Mali Redelonghi");
	add_struct(buf, "Špela Redelonghi");
	add_struct(buf, "Zala Redelonghi");

	// test
	char *start = buf;
	char *pointer = start + (size_t)16;
	printf("start: %p, pointer: %p\n", start, pointer);
	printf("count: %ld, name: %s\n", strcts_global_count, pointer);


	return 0;
} // end MAIN


/* add struct to buf memory region */
void add_struct(char *buf, char *name) {
	mystrct_t strct = {0};
	strct.count = strcts_global_count + 1;
	size_t next_offset = sizeof(mystrct_t) * strcts_global_count;

	strcpy(strct.name, name);
	memcpy(buf + next_offset, &strct, sizeof(mystrct_t));

	strcts_global_count += 1;
}

