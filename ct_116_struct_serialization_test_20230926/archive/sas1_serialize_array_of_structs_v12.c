/*
 * sas1_serialize_array_of_structs_v12.c
 *
 * 20230926_01 (en)
 * 20230927_02 (en)
 * 20230928_03 (d)
 * 20230928_04 (en)
 * 20230929_05 (en)
 * 20231006_06 (d)
 */
#include <stdio.h>
#include <stdlib.h>               // exit()
#include "serialize_v5.h"         // v12
#include "fpath_to_abspath_v2.h"  // v11


/* MAIN */
int main(int argc, char **argv) {
	static char buffer[BUF_SIZE];
	char *buf = (char *)&buffer;

	element_add_to_buf(buf, "Gregor Redelonghi");
	element_add_to_buf(buf, "Tadeja Mali Redelonghi");
	element_add_to_buf(buf, "Špela Redelonghi");
	element_add_to_buf(buf, "Zala Redelonghi");
	element_add_to_buf(buf, "Mark Redelonghi");
	element_add_to_buf(buf, "Sisi Redelonghi");
	element_add_to_buf(buf, "Berthold Sthrolzhenburger");

#if 0
	// test
	printf("---\n");
	elements_print_all(buf, elements_global_count);
	elements_print_single(buf, 8, elements_global_count);
	elements_print_single(buf, 3, elements_global_count);
#endif

	char fpath[PATH_MAX];
	char *fname = "elements_array.bin";
	fpath_make_absolute(fpath, fname, argv[0]); // v10

	FILE *fp = fopen(fpath, "wb");       // v10

	if (fp == NULL) {
		fprintf(stderr, "Could NOT write to file: %s\n", fname);
		exit(1);
	}

	/* elements_global_count updated in each element_add_to_buf()
	 * declared and defined in serialize.h
	 */
	fwrite(buf, sizeof(Element_t), elements_global_count, fp);
	printf("---\nArray of %ld elements serialized to '%s'\n", elements_global_count, fname);

	fclose(fp);


	return 0;
} // end MAIN

