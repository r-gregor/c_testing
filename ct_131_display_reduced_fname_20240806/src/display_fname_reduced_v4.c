/*
 * fname: display_fname_reduced_v4.c
 * 20240806_01_en -- v1
 * 20240806_02_en -- v2: put base logic into function display_fname_reduced()
 * 20240806_03_en -- v3: multiple filenames
 * 20240806_04_en -- v4: middle = 'string'
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS  40
#define LAST_CHARS 13

// void display_reduced(char *);
void display_reduced(char *, size_t);

int main(void) {
	// char *fname = "tst_just_a_long_testfilename_with_timestamp_20240806.txt";
	char fnames[][125] = {"tst_just_a_long_testfilename_with_timestamp_20240806.txt",
		                 "second-fname-with-really-long-long-long-long-long-long-long-long-long-long-fname_20240102.txt",
		                 "A_third_file_20241231.txt",
		                 "A_cool_file_20241231.txt",
		                 "This-is-really-crazy-stuff_20240806.txt",
		                 "fname4_20240815.txt"
	};

	size_t fnames_num = sizeof(fnames)/sizeof(fnames[0]);

	/* v3: run new function on multiple filenames */
	size_t rdc_len = 25;
	printf("Reducing file names to length of %ld characters:\n\n", rdc_len);
	for (int i = 0; i < fnames_num; i++) {
		display_reduced(fnames[i], 25);
		printf("---\n");
	}

	return 0;
}


void display_reduced(char *original, size_t maxlen) {
	/* NOT NEEDED !!
	if (maxlen <= LAST_CHARS) {
		maxlen = LAST_CHARS + 2;
	}
	*/

	char *fname = original;
	char *rdc_fname = NULL;

	/*
	 * max chars to be displayed  + mid_len + 1x '\0'
	 */
	char *middle = "[@]";
	size_t mid_len = strlen(middle);
	size_t rdc_size = maxlen + mid_len + 1;

	if (strlen(fname) <= maxlen) {
		rdc_fname = fname;
		printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));
		printf("Result:   '%s', length: %ld chars\n", rdc_fname, strlen(rdc_fname));
		return;
	}

	rdc_fname = calloc((rdc_size), sizeof(char));
	int pos = 0;
	int first_part = maxlen - LAST_CHARS - mid_len;
	while (pos < first_part) {
		rdc_fname[pos] = fname[pos];
		pos++;
	}

	for (int k = 0; k < mid_len; k++) {
		rdc_fname[pos++] = middle[k];
	}

	int last = LAST_CHARS;
	while (pos < MAX_CHARS) {
		rdc_fname[pos] = fname[strlen(fname) - last];
		pos++;
		last--;
	}

	printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));
	printf("Result:   '%s', length: %ld chars\n", rdc_fname, strlen(rdc_fname));
	free(rdc_fname);
}

