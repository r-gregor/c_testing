/*
 * main4.c
 * v4
 * 202400304_04_mdb
 */

#include <stdio.h>
#include <string.h>
#include "strip_reduce_str_spscs4.h"

char final[MAX_MULT_SPCS_STR_LEN];
char final2[MAX_MULT_SPCS_STR_LEN];


/* MAIN */
int main(void) {
	
	char *stringZ[] = {"     TEST STRING          WITH SOME   MULTIPLE            SPACES",
	                   "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES",
	                   "  ROGERG    IHGNOLEDER DNA     AJEDAT       ILAM  IHGNOLEDER",
	                   "     BERTHOLD SCHTROLTZENBURGER     AND THE    MAHNIFICENT EIGHT                          "
	};

	CString dst = {
		.str1 = final,
		.str2 = final2
	};

	for (size_t i = 0; i < sizeof(stringZ) / sizeof(stringZ[0]); ++i) {
		printf("Original string: \"%s\"\n", stringZ[i]);
		printf("Original string: "); pprnt(stringZ[i]);
		printf("---\n");
		multiple_spcs_as_one(stringZ[i], dst.str1);
		strip_leading_trailing_spcs(dst.str1, dst.str2);
		printf("Striped: \"%s\"\n", dst.str2);
		printf("Striped: "); pprnt(dst.str2);
		printf("-----------------------------------------------------------------------------\n\n");
		memset(final, 0, MAX_MULT_SPCS_STR_LEN);
		memset(final2, 0, MAX_MULT_SPCS_STR_LEN);
	}

	return 0;
} /* end MAIN */

