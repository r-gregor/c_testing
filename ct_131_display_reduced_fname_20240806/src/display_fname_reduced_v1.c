/*
 * fname: display_fname_reduced_v1.c
 * 20240806_01_en -- v1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS  40
#define LAST_CHARS 13


int main(void) {
	char *fname = "tst_just_a_long_testfilename_with_timestamp_20240806.txt";
	printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));

	/*
	 * max chars to be displajed +1x '\0' + 3x'.' + 2x ' ', at both ends of dots ...
	 */
	char *rfname = calloc((MAX_CHARS + 1 + 3 + 2), sizeof(char));
	char middle = '#';
	int pos = 0;
	int first_part = MAX_CHARS - LAST_CHARS - 1;
	while (pos < first_part) {
		rfname[pos] = fname[pos];
		pos++;
	}

	rfname[pos++] = middle;

	int last = LAST_CHARS;
	while (pos < MAX_CHARS) {
		rfname[pos] = fname[strlen(fname) - last];
		pos++;
		last--;
	}

	printf("Result:   '%s', length: %ld chars\n", rfname, strlen(rfname));
	free(rfname);

	return 0;
}

