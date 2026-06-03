/*
 * main5.c
 * v5
 * 202400304_05_en
 */

#include <stdio.h>
#include <string.h>
#include "mf_strip_reduce_str_spcs5.h"

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
		printf("Original string: "); mf_pprnt(stringZ[i]);
		printf("---\n");
		char *striped = mf_strip_reduce(stringZ[i]);
		printf("Striped: \"%s\"\n", striped);
		printf("Striped: "); mf_pprnt(striped);
		printf("-----------------------------------------------------------------------------\n\n");
		memset(final, 0, MAX_MULT_SPCS_STR_LEN);
		memset(final2, 0, MAX_MULT_SPCS_STR_LEN);
	}

	return 0;
} /* end MAIN */

