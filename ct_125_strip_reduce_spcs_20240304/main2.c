#include <stdio.h>
#include <string.h>
#include "strip_reduce_str_spscs.h"


int main(void) {
	
	char *stringZ[] = {"     TEST STRING          WITH SOME   MULTIPLE            SPACES",
	                   "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES",
	                   "  ROGERG    IHGNOLEDER DNA     AJEDAT       ILAM  IHGNOLEDETR",
	                   "     BETHOLD SSCROLTZENBURGER     AND THE    MAHNIFICENT EIGHT                          "
	};

	/*
	printf("Original string: \"%s\"\n", mystring1);
	printf("Original string: "); pprnt(mystring1);
	printf("Original string2: \"%s\"\n", mystring2);
	printf("Original string2: "); pprnt(mystring2);

	printf("---\n");
	// char *final = multiple_spcs_as_one(strip_leading_trailing_spcs(mystring2));
	char *final1 = strip_reduce(mystring1);
	printf("Striped: \"%s\"\n", final1);
	printf("Striped: "); pprnt(final1);
	printf("---\n");
	char *final2 = strip_reduce(mystring2);
	printf("Striped: \"%s\"\n", final2);
	printf("Striped: "); pprnt(final2);
	*/

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
}
