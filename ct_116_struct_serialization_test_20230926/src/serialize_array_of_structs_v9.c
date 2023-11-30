/*
 * array_of_structs_serialization_v8.c
 * v9: struct and struct functions definitions removed to serilize.h
 *
 * 20230926_01 (en)
 * 20230927_02 (en)
 * 20230928_03 (d)
 * 20230928_04 (en)
 * TODO: get current working dir for binary file to store data into
 *       (in cn_088_ ...)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // exit()
#include <stdint.h>
#include <stddef.h>     // offsetof()
#include "serialize.h"  // v9


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
	print_single_struct(buf, 8, strcts_global_count);
	print_single_struct(buf, 3, strcts_global_count);
#endif
	
	char *fname = "bin/structs_array.bin";
	FILE *fp = fopen(fname, "wb");

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

