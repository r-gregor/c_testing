/*
 * mutable_string_test.c
 * 20240603_02_en
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50

void print_full_varmem(char *string);

/* MAIN */
int main(void) {

	char *mstr = malloc(MAX_NAME_LEN); // mutable string
	memset(mstr, 0, MAX_NAME_LEN);

	char *src = "Tadeja Mali";
	strcpy(mstr, src);

	printf("before change: \"%s\"\n", mstr);

	char *add = " Redelonghi";
	char *start = mstr + (strlen(mstr));
	for (int i = 0; i < strlen(add); ++i) {
		*(start + i) = *(add + i);
	}

	// printf("after change:  \"%s\"\n", mstr);
	printf("after change:  ");
	print_full_varmem(mstr);

	/* ============================================ */
	printf("---\n");

	char mstr2[MAX_NAME_LEN]; // mutable string

	char *src2 = "Gregor";
	strcpy(mstr2, src2);

	printf("Without memset to '0':\n");
	printf("before change: \"%s\"\n", mstr2);

	char *add2 = " Redelonghi";
	char *start2 = mstr2 + (strlen(mstr2));
	for (int i = 0; i < strlen(add2); ++i) {
		*(start2 + i) = *(add2 + i);
	}
	*(start2 + strlen(add2)) = '\0';

	// printf("after change:  \"%s\"\n", mstr2);
	printf("after change:  ");
	print_full_varmem(mstr2);

	/* ============================================ */
	printf("---\n");

	char mstr3[MAX_NAME_LEN]; // mutable string
	memset(mstr3, 0, MAX_NAME_LEN);

	char *src3 = "Gregor";
	strcpy(mstr3, src3);

	printf("With memset to '0':\n");
	printf("before change: \"%s\"\n", mstr3);

	char *add3 = " Redelonghi";
	char *start3 = mstr3 + (strlen(mstr3));
	for (int i = 0; i < strlen(add3); ++i) {
		*(start3 + i) = *(add3 + i);
	}
	*(start3 + strlen(add3)) = '\0';

	// printf("after change:  \"%s\"\n", mstr3);
	printf("after change:  ");
	print_full_varmem(mstr3);


	return 0;
} /* end MAIN */

/*
 * print all string positions including 0-s
 */
void print_full_varmem(char *string) {
	printf("\"");
	for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
		char chr = *(string + i);
		if (chr == '\0') {
			printf(".");
		} else {
			printf("%c", chr);
		}
	}
	printf("\"\n");
}
