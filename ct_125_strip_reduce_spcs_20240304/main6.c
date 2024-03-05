/*
 * main6.c
 * v6
 * 202400304_06_en
 */

#include <stdio.h>
#include <string.h>
#include "strip_reduce_str_spscs6.h"

char striped[MAX_MULT_SPCS_STR_LEN];
char reduced[MAX_MULT_SPCS_STR_LEN];


/* MAIN */
int main(void) {
	
	char *stringZ[] = {"     TEST STRING          WITH SOME   MULTIPLE            SPACES",
	                   "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES",
	                   "  ROGERG    IHGNOLEDER DNA     AJEDAT       ILAM  IHGNOLEDER",
	                   "     BERTHOLD SCHTROLTZENBURGER     AND THE    MAHNIFICENT EIGHT                          "
	};

	for (size_t i = 0; i < sizeof(stringZ) / sizeof(stringZ[0]); ++i) {
		printf("-----------------------------------------------------------------------------\n");
		printf("Original string: \"%s\"\n", stringZ[i]);
		printf("Original string: "); pprnt(stringZ[i]);
		printf("---\n");
		strip_leading_trailing_spcs(stringZ[i], striped);
		multiple_spcs_as_one(stringZ[i], reduced);
		char *striped_reduced = strip_reduce(stringZ[i]);
		printf("Striped: \"%s\"\n", striped);
		printf("Striped: "); pprnt(striped);
		printf("---\n");
		printf("Reduced: \"%s\"\n", reduced);
		printf("Reduced: "); pprnt(reduced);
		printf("---\n");
		printf("Striped and reduced: \"%s\"\n", striped_reduced);
		printf("Striped and reduced: "); pprnt(striped_reduced);
	}

	printf("-----------------------------------------------------------------------------\n");
	char *nl = "     Zala in      Mark,    ter Špela            in  Tadeja   Mali Redelonghi                       ";
	printf("Original string: \"%s\"\n", nl);
	printf("Original string: "); pprnt(nl);
	printf("---\n");
	char *srnl = strip_reduce(nl);
	printf("Striped and reduced: \"%s\"\n", strip_reduce(nl));
	printf("Striped and reduced: "); pprnt(srnl);

	return 0;
} /* end MAIN */

