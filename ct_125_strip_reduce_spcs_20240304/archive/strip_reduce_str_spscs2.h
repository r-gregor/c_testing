/*
 * v2
 * 20240304_02_en
 */

#ifndef _STRIP_REDUCE_STR_SPSCS_H
#define _STRIP_REDUCE_STR_SPSCS_H

#ifndef MAX_MULT_SPCS_STR_LEN
#define MAX_MULT_SPCS_STR_LEN 256
#endif

char *multiple_spcs_as_one(char *string);
char *strip_leading_trailing_spcs(char *source);
void pprnt(char *line);


/* ======== IMPLEMENTATIONS ========= */

/*
 * reduce multiple spaces into one space
 * @param char *source (input) string
 * @return char *result to new string
 */
char *multiple_spcs_as_one(char *string) {
	static char dest1[MAX_MULT_SPCS_STR_LEN];
	char *result = dest1;

	while (*string != '\0') {
		if (*string != ' ') {
			*result++ = *string++;
		} else {
			*result++ = ' ';
			while (*string == ' ') string++;
		}
	}

	return dest1;
}

/*
 * strip off leading and trailing spaces
 * @param char *source (input) string
 * @return char *result to new string
 */
char *strip_leading_trailing_spcs(char *source) {
	static char dest2[MAX_MULT_SPCS_STR_LEN];
	if (*source == ' ') {
		while (*source == ' ') source++;
	}

	/* instead of strcpy() */
	char *result = dest2;
	while (*source != '\0') {
		*result++ = *source++;
	}

	int pos = strlen(dest2) - 1;
	while (dest2[pos] == ' ') {
		dest2[pos] = '\0';
		pos--;
	}

	return dest2;
}


char *strip_reduce(char *source) {
	return multiple_spcs_as_one(strip_leading_trailing_spcs(source));
}




/*
 * print string with special characters for space ' '
 * @param char *source (input) string
 * @retur void: print out reformated string
 */
void pprnt(char *line) {
	printf("\"");
	while(*line != '\0') {
		if (*line == ' ') {
			printf("~");
		} else {
			printf("%c", *line);
		}
		line++;
	}
	printf("\"\n");
}

#endif
