/*
 * display_fname_reduced_v5.c
 * 20240806_01_en -- v1
 * 20240806_02_en -- v2: put base logic into function display_fname_reduced()
 * 20240806_03_en -- v3: multiple filenames
 * 20240806_04_en -- v4: sep_char = 'string'
 * 20240806_05_en -- v5: rdc_fname from malloc-ed to pointer to buffer
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS  40 // ???
#define LAST_CHARS 13 // '_' + tomestamp + '.txt'

void display_reduced(char *, size_t, char *);

int main(void) {

	/* array with test filenames */
	char fnames[][125] = {"tst_just_a_long_testfilename_with_timestamp_20240806.txt",
		                 "second-fname-with-really-long-long-long-long-long-long-long-long-long-long-fname_20240102.txt",
		                 "A_third_file_20241231.txt",
		                 "A_cool_file_20241231.txt",
		                 "20240222.txt",
		                 "This-is-really-crazy-stuff_20240806.txt",
		                 "fname4_20240815.txt"
	};

	size_t fnames_num = sizeof(fnames)/sizeof(fnames[0]);
	char *sep_char = "(#)";

	/* v5 */
	/* v3: run new function on multiple filenames */
	size_t rdc_len = 25;
	printf("Reducing file names to length of %ld characters:\n\n", rdc_len);
	for (int i = 0; i < fnames_num; i++) {
		display_reduced(fnames[i], rdc_len, sep_char);
		printf("---\n");
	}

	return 0;
}


void display_reduced(char *original, size_t maxlen, char *sep_char) {

	char *fname = original;
	char *rdc_fname = NULL;

	/*
	 * v5
	 * max chars to be displayed  + mid_len + 1x '\0'
	 */
	size_t mid_len = strlen(sep_char);
	size_t buff_size = maxlen + mid_len + 1;
	char buffer[buff_size];

	if (strlen(fname) <= maxlen) {
		rdc_fname = fname;
		printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));
		printf("Result:   '%s', length: %ld chars\n", rdc_fname, strlen(rdc_fname));
		return;
	}


	/* v5 */
	// rdc_fname = calloc((maxlen + mid_len + 1), sizeof(char));
	rdc_fname = buffer;

	int pos = 0;
	int first_part = maxlen - LAST_CHARS - mid_len;
	while (pos < first_part) {
		rdc_fname[pos] = fname[pos];
		pos++;
	}

	for (int k = 0; k < mid_len; k++) {
		rdc_fname[pos++] = sep_char[k];
	}

	int last = LAST_CHARS;
	while (pos < MAX_CHARS) {
		rdc_fname[pos] = fname[strlen(fname) - last];
		pos++;
		last--;
	}

	printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));
	printf("Result:   '%s', length: %ld chars\n", rdc_fname, strlen(rdc_fname));
}

