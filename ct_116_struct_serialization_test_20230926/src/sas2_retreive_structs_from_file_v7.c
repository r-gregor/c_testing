/*
 * sas2_retreive_structs_from_file_v7.c
 * 20230927_01 (en)
 * 20230927_02 (d)
 * 20230928_03 (en)
 * 20230929_04 (en)
 * 20231006_05 (d)
 */
#include <stdio.h>
#include <stdlib.h>                    // exit()
#include "serialize_v5.h"              // v7
#include "fpath_to_abspath_v2.h"       // v6


/* MAIN */
int main(int argc, char **argv) {

	char fpath[PATH_MAX];
	char *fname = "elements_array.bin";
	fpath_make_absolute(fpath, fname, argv[0]); // v5


	FILE *fp = fopen(fpath, "rb");       // v5

	if (fp == NULL) {
		fprintf(stderr, "Could NOT read from file: %s\n", fname);
		fprintf(stderr, "Must run bin/sas1_... first!\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	uint64_t fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	uint64_t elements_count = fsize / sizeof(Element_t);

#if 1
	// test
	printf("Size of file '%s': %4ld\n", fname, fsize);
	printf("Number of elements in buffer:      %4ld\n", elements_count);
	printf("Size of element in buffer:         %4ld\n", fsize/elements_count);
#endif

	char buffer[fsize];
	char *buf = (char *)&buffer;
	fread(buf, sizeof(Element_t), elements_count, fp);
	/*
	fread((char *)&buffer, sizeof(Element_t), elements_count, fp);
	*/

	fclose(fp);

	printf("---\n");

	elements_print_all(buf, elements_count);
	elements_print_single(buf, 8, elements_count); // test: outside range
	elements_print_single(buf, 3, elements_count);
	elements_print_single(buf, 6, elements_count);
	/*
	elements_print_all((char *)&buffer, elements_count);
	...
	*/

	return 0;
} // end MAIN

