/*
 * main2.c
 * v2
 * 202400304_02_en
 */

#include <stdio.h>
#include <string.h>
#include "strip_reduce_str_spscs.h"


/* MAIN */
int main(void) {
	
	char *stringZ[] = {"     TEST STRING          WITH SOME   MULTIPLE            SPACES",
	                   "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES",
	                   "  ROGERG    IHGNOLEDER DNA     AJEDAT       ILAM  IHGNOLEDER",
	                   "     BETHOLD SSCROLTZENBURGER     AND THE    MAHNIFICENT EIGHT                          "
	};

	for (size_t i = 0; i < sizeof(stringZ) / sizeof(stringZ[0]); ++i) {
		printf("Original string: \"%s\"\n", stringZ[i]);
		printf("Original string: "); pprnt(stringZ[i]);
		printf("---\n");
		char *final = strip_reduce(stringZ[i]);
		printf("Striped: \"%s\"\n", final);
		printf("Striped: "); pprnt(final);
		printf("-----------------------------------------------------------------------------\n\n");
	}

	return 0;
} /* end MAIN */

