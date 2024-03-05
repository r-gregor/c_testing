/*
 * main.c
 * v1
 * 20240304_01_en
 */

#include <stdio.h>
#include <string.h>
#include "strip_reduce_str_spscs.h"


/* MAIN */
int main(void) {
	
	char *mystring = "     TEST STRING          WITH SOME   MULTIPLE            SPACES";

	printf("Original string: \"%s\"\n", mystring);
	printf("Original string: "); pprnt(mystring);

	printf("---\n");
	char *striped = strip_leading_trailing_spcs(mystring);
	printf("Striped: \"%s\"\n", striped);
	printf("Striped: "); pprnt(striped);


	printf("---\n");
	char *reduced = multiple_spcs_as_one(striped);
	printf("Striped: \"%s\"\n", reduced);
	printf("Striped: "); pprnt(reduced);

	printf("\n==========================================================\n");

	char *mystring2 = "     TEST          STRING2          WITH SOME   MULTIPLE       SPACES";

	printf("Original string2: \"%s\"\n", mystring2);
	printf("Original string2: "); pprnt(mystring2);

	printf("---\n");
	// char *final = multiple_spcs_as_one(strip_leading_trailing_spcs(mystring2));
	char *final = strip_reduce(mystring2);
	printf("Striped: \"%s\"\n", final);
	printf("Striped: "); pprnt(final);

	return 0;
} /* end MAIN */

