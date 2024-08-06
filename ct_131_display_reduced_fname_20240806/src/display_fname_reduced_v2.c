/*
	* fname:display_fname_reduced_v2.c
 * 20240806_01_en -- v1
 * 20240806_02_en -- v2: put base logic into function display_fname_reduced()
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS  40
#define LAST_CHARS 13

// void display_reduced(char *);
void display_reduced(char *, size_t);

int main(void) {
	char *fname = "tst_just_a_long_testfilename_with_timestamp_20240806.txt";

	/* v2: new function */
	display_reduced(fname, 25);

	return 0;
}


void display_reduced(char *original, size_t maxlen) {
	if (maxlen <= LAST_CHARS) {
		maxlen = LAST_CHARS + 2;
	}

	char *fname = original;
	printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));

	/*
	 * max chars to be displajed +1x '\0' + 3x'.' + 2x ' ', at both ends of dots ...
	 */
	char *rfname = calloc((maxlen + 1 + 3 + 2), sizeof(char));
	char middle = '#';
	int pos = 0;
	int first_part = maxlen - LAST_CHARS - 1;
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
}

