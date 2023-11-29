/*
 * array_of_structs_serialization_v8.c
 * v10: include "abspath.h" --> serialize to file relative
 *      to exectable (absolute path)
 *
 * 20230926_01 (en)
 * 20230927_02 (en)
 * 20230928_03 (d)
 * 20230928_04 (en)
 * 20230929_05 (en)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // exit()
#include <stdint.h>
#include <stddef.h>     // offsetof()
#include "serialize.h"  // v9
#include "abspath.h"    // v10


/* MAIN */
int main(int argc, char **argv) {
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
	print_single_struct(buf, 8, strcts_global_count);
	print_single_struct(buf, 3, strcts_global_count);
#endif

	char fpath[PATH_MAX];
	char *fname = "structs_array.bin";
	file_abspath(fpath, fname, argv[0]); // v10

	FILE *fp = fopen(fpath, "wb");       // v10

	if (fp == NULL) {
		fprintf(stderr, "Could NOT write to file: %s\n", fname);
		exit(1);
	}

	/* strcts_global_count updated in each add_struct()
	 * declared and defined in serialize.h
	 */
	fwrite(buf, sizeof(mystrct_t), strcts_global_count, fp);
	printf("Array of struct serialized to %s\n", fname);

	fclose(fp);


	return 0;
} // end MAIN

