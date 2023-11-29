/*
 * retreive_structs_from_file_v2.c
 * 20230927_01 (en)
 * 20230927_02 (d)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit()
#include <stdint.h>
#include <stddef.h> // offsetof()


/*
 * Have to know definition of struct to decompose buffer into
 * individual struct: sizeof(mystrct_t)
 * TODO: put it into header file
 */
typedef struct mystrct {
	uint64_t offset;
	uint64_t count;
	char name[48];
} mystrct_t;

void print_all_structs(char *buf, uint64_t structs_count);
void print_single_struct(char *buf, uint64_t count, uint64_t structs_count);


/* MAIN */
int main(void) {
	char *fname = "structs_array.bin";
	FILE *fp = fopen(fname, "rb");

	if (fp == NULL) {
		fprintf(stderr, "Could NOT read from file: %s\n", fname);
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	uint64_t fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	uint64_t structs_count = fsize / sizeof(mystrct_t);

#if 1
	// test
	printf("Size of file%s: %ld\n", fname, fsize);
	printf("Number of structs in buffer: %ld\n", structs_count);
#endif

	char buffer[fsize];
	char *buf = (char *)&buffer;
	fread(buf, sizeof(mystrct_t), structs_count, fp);
	/*
	fread((char *)&buffer, sizeof(mystrct_t), structs_count, fp);
	*/

	fclose(fp);

	printf("---\n");


	print_all_structs(buf, structs_count);
	print_single_struct(buf, 8, structs_count); // test: outside range
	print_single_struct(buf, 3, structs_count);
	print_single_struct(buf, 6, structs_count);
	/*
	print_all_structs((char *)&buffer, structs_count);
	...
	*/

	return 0;
} // end MAIN


/* print single struct info */
void print_single_struct(char *buf, uint64_t count, uint64_t structs_count) {
	if (count > structs_count) {
		fprintf(stderr, "Tried to print struct number %ld: ", count);
		fprintf(stderr, "buffer capacity owerflow!\n");
		printf("---\n");
		return;
	}

	char *start = buf + (count - 1) * sizeof(mystrct_t);
	char *cnt = start + (uint64_t)offsetof(mystrct_t, count);
	char *pointer = start + (uint64_t)offsetof(mystrct_t, name);
	// printf("start: %p, cnt: %p, pointer: %p\n", start, cnt, pointer);
	printf("count: %ld\n", (uint64_t)*cnt);
	printf("name:  %s\n", pointer);
	printf("---\n");
}

/* print all structs given the structs_count */
void print_all_structs(char *buf, uint64_t structs_count) {
	for (uint64_t count = 1; count <= structs_count; count++) {
		print_single_struct(buf, count, structs_count);
	}
}

