/*
 * main6.c
 * v6
 * 202400304_06_en
 */

#include <stdio.h>
#include <string.h>
#include "mf_strip_reduce_str_spcs6.h"

char striped[MAX_MULT_SPCS_STR_LEN];
char reduced[MAX_MULT_SPCS_STR_LEN];


/* MAIN */
int main(void) {
	
	char *stringZ[] = {"     TEST STRING          WITH SOME   MULTIPLE            SPACES",
	                   "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES",
	                   "  ROGERG    IHGNOLEDER DNA     AJEDAT       ILAM  IHGNOLEDER",
	                   "     BERTHOLD SCHTROLTZENBURGER     AND THE    MAHNIFICENT EIGHT                          "
	};

	/* LOOP */
	for (size_t i = 0; i < sizeof(stringZ) / sizeof(stringZ[0]); ++i) {
		printf("-----------------------------------------------------------------------------\n");
		printf("Original string: \"%s\"\n", stringZ[i]);
		printf("Original string: "); mf_pprnt(stringZ[i]);
		printf("---\n");
		mf_strip_lead_trail_spcs(stringZ[i], striped);
		mf_reduce_multiple_spcs(stringZ[i], reduced);
		char *striped_reduced = mf_strip_reduce(stringZ[i]);
		printf("Striped: \"%s\"\n", striped);
		printf("Striped: "); mf_pprnt(striped);
		printf("---\n");
		printf("Reduced: \"%s\"\n", reduced);
		printf("Reduced: "); mf_pprnt(reduced);
		printf("---\n");
		printf("Striped and reduced: \"%s\"\n", striped_reduced);
		printf("Striped and reduced: "); mf_pprnt(striped_reduced);
	}

	/* SINGLE */
	printf("-----------------------------------------------------------------------------\n");
	char *nl = "     Zala in      Mark,    ter Špela            in  Tadeja   Mali Redelonghi                       ";
	printf("Original string: \"%s\"\n", nl);
	printf("Original string: "); mf_pprnt(nl);
	printf("---\n");
	char *srnl = mf_strip_reduce(nl);
	printf("Striped and reduced: \"%s\"\n", mf_strip_reduce(nl));
	printf("Striped and reduced: "); mf_pprnt(srnl);

	return 0;
} /* end MAIN */

