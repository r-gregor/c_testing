/*
 * mutable_string_test.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {

	char *mstr = malloc(100); // mutable string
	memset(mstr, 0, 100);

	char *src = "Tadeja Mali";
	strcpy(mstr, src);

	printf("before change: \"%s\"\n", mstr);

	char *add = " Redelonghi";
	char *start = mstr + (strlen(mstr));
	for (int i = 0; i < strlen(add); ++i) {
		*(start + i) = *(add + i);
	}

	printf("after change:  \"%s\"\n", mstr);

	/* ============================================ */
	printf("---\n");

	char mstr2[100]; // mutable string

	char *src2 = "Gregor";
	strcpy(mstr2, src2);

	printf("before change: \"%s\"\n", mstr2);

	char *add2 = " Redelonghi";
	char *start2 = mstr2 + (strlen(mstr2));
	for (int i = 0; i < strlen(add2); ++i) {
		*(start2 + i) = *(add2 + i);
	}
	*(start2 + strlen(add2)) = '\0';

	printf("after change:  \"%s\"\n", mstr2);


	return 0;
}

