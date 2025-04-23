/*
 * mf_strip_reduce_str_spcs.h
 * from ct_125_strip_reduce_spcs_20240304/
 * only mf_strip_reduce() function used
 */

#ifndef _MF_STRIP_REDUCE_STR_SPCS_H
#define _MF_STRIP_REDUCE_STR_SPCS_H

#ifndef MAX_MULT_SPCS_STR_LEN
#define MAX_MULT_SPCS_STR_LEN 256
#endif

char *mf_strip_reduce(char *src);


/* ======== IMPLEMENTATIONS ========= */

char *mf_strip_reduce(char *src) {
	/* strip_leading_trailing_spcs(char *src, char *dst) */
	char buff1[MAX_MULT_SPCS_STR_LEN] = {0};
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
	static char buff2[MAX_MULT_SPCS_STR_LEN] = {0};
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

#endif

