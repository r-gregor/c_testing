/*
 * retreive_structs_from_file_v5.c
 * v4: struct and print function removed into serialize.h
 * 20230927_01 (en)
 * 20230927_02 (d)
 * 20230928_03 (en)
 * 20230929_04 (en))
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // exit()
#include <stdint.h>
#include <stddef.h>     // offsetof()
#include "serialize.h"  // v4
#include "abspath.h"    // v5


/* MAIN */
int main(int argc, char **argv) {

	char fpath[PATH_MAX];
	char *fname = "structs_array.bin";
	file_abspath(fpath, fname, argv[0]); // v5


	FILE *fp = fopen(fpath, "rb");       // v5

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

