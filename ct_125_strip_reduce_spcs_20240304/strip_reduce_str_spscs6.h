/*
 * v6
 * 20240304_06_en
 */

#ifndef _STRIP_REDUCE_STR_SPSCS_H
#define _STRIP_REDUCE_STR_SPSCS_H

#ifndef MAX_MULT_SPCS_STR_LEN
#define MAX_MULT_SPCS_STR_LEN 256
#endif

void multiple_spcs_as_one(char *src, char *dst);
void strip_leading_trailing_spcs(char *src, char *dst);
char *strip_reduce(char *src);
void pprnt(char *line);


/* ======== IMPLEMENTATIONS ========= */
/*
 * reduce multiple spaces into one space
 * @param char *source (input) string
 * @return char *dst to new string
 */
void multiple_spcs_as_one(char *src, char *dst) {

	while (*src != '\0') {
		if (*src != ' ') {
			*dst++ = *src++;
		} else {
			*dst++ = ' ';
			while (*src == ' ') src++;
		}
	}
}

/*
 * strip off leading and trailing spaces
 * @param char *source (input) string
 * @return char *result to new string
 */
void strip_leading_trailing_spcs(char *src, char *dst) {
	if (*src == ' ') {
		while (*src == ' ') src++;
	}

	/* instead of strcpy() */
	while (*src != '\0') {
		*dst++ = *src++;
	}

	int pos = strlen(dst) - 1;
	while (dst[pos] == ' ') {
		dst[pos] = '\0';
		pos--;
	}
}

char *strip_reduce(char *src) {
	/* strip_leading_trailing_spcs(char *src, char *dst) */
	static char buff1[MAX_MULT_SPCS_STR_LEN];
	memset(buff1, 0, MAX_MULT_SPCS_STR_LEN);
	char *dst1 = buff1;
	if (*src == ' ') {
		while (*src == ' ') src++;
	}

	/* instead of strcpy() */
	while (*src != '\0') {
		*dst1++ = *src++;
	}

	int pos = strlen(dst1) - 1;
	while (dst1[pos] == ' ') {
		dst1[pos] = '\0';
		pos--;
	}


	/* void multiple_spcs_as_one(char *src, char *dst) */
	static char buff2[MAX_MULT_SPCS_STR_LEN];
	memset(buff2, 0, MAX_MULT_SPCS_STR_LEN);
	char *result = buff2;
	char *dst2 = buff1;
	while (*dst2 != '\0') {
		if (*dst2 != ' ') {
			*result++ = *dst2++;
		} else {
			*result++ = ' ';
			while (*dst2 == ' ') dst2++;
		}
	}
	result = buff2;
	return result;
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

