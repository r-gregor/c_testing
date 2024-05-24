/*
 * for_each_file_in_dir.c
 * 20240524_01 (en) v6
 */
#include "ubuild.h"
#define HL3 printf("---\n");

int main(void) {

	char fnames[][64] = {"TESTDIR", "TRII/subtrii_1/dir_1"};
	// const char *dirname = "TESTDIR"
	// const char *dirname = "TRII/subtrii_1/dir_1";

	for (int i = 0; i < 2; i++) {
		printf("---\nFiles in %s:\n", fnames[i]);

		FOREACH_FILE_IN_DIR(dn, fnames[i], {
			if (*dn != '.' && *dn != '..') {
				printf("%s\n", dn );
			}
		});
		printf("\n");
	}
	return 0;
}

