/* mult_spcs_as_one.c
 * v1
 * 20240304_01 (en)
 */
#include <stdio.h>
#include <string.h>

#ifndef MAX_MULT_SPCS_STR_LEN
#define MAX_MULT_SPCS_STR_LEN 256
#endif

char *multiple_spcs_as_one(char *string);

/* MAIN */
int main(void) {

	char *string1 = "GREGOR       REDELONGHI  IN TADEJA    MALI              REDELONGHI";

	printf("Original string: \"%s\"\n", string1);
	printf("chars num:       %ld\n", strlen(string1));

	char *shorter = NULL;
	shorter = multiple_spcs_as_one(string1);
	printf("Reduced string: \"%s\"\n", shorter);

	return 0;
} /* end main */


char *multiple_spcs_as_one(char *string) {
	static char dest[MAX_MULT_SPCS_STR_LEN];
	char *result = dest;

	while (*string != '\0') {
		if (*string != ' ') {
			*result++ = *string++;
		} else {
			*result++ = ' ';
			while (*string == ' ') string++;
		}
	}

	return dest;
}

