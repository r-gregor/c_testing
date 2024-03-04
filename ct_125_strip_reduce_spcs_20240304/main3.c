/*
 * main3.c
 * v3
 * 202400304_03_mdb
 */

#include <stdio.h>
#include <string.h>
#include "strip_reduce_str_spscs3.h"

char final[MAX_MULT_SPCS_STR_LEN];
char final2[MAX_MULT_SPCS_STR_LEN];


/* MAIN */
int main(void) {
	
	char *stringZ[] = {"     TEST STRING          WITH SOME   MULTIPLE            SPACES",
	                   "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES",
	                   "  ROGERG    IHGNOLEDER DNA     AJEDAT       ILAM  IHGNOLEDER",
	                   "     BERTHOLD SCHTROLTZENBURGER     AND THE    MAHNIFICENT EIGHT                          "
	};

	for (size_t i = 0; i < sizeof(stringZ) / sizeof(stringZ[0]); ++i) {
		printf("Original string: \"%s\"\n", stringZ[i]);
		printf("Original string: "); pprnt(stringZ[i]);
		printf("---\n");
		multiple_spcs_as_one(stringZ[i], final);
		strip_leading_trailing_spcs(final, final2);
		printf("Striped: \"%s\"\n", final2);
		printf("Striped: "); pprnt(final2);
		printf("-----------------------------------------------------------------------------\n\n");
		memset(final, 0, MAX_MULT_SPCS_STR_LEN);
		memset(final2, 0, MAX_MULT_SPCS_STR_LEN);
	}

	return 0;
} /* end MAIN */

