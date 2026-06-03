/*
	* fname: display_fname_reduced_v3.c
 * 20240806_01_en -- v1
 * 20240806_02_en -- v2: put base logic into function display_fname_reduced()
 * 20240806_03_en -- v3: multiple filenames
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
	for (int i = 0; i < fnames_num; i++) {
		display_reduced(fnames[i], 25);
		printf("---\n");
	}

	return 0;
}


void display_reduced(char *original, size_t maxlen) {
	if (maxlen <= LAST_CHARS) {
		maxlen = LAST_CHARS + 2;
	}

	char *fname = original;
	char *rfname = NULL;

	if (strlen(fname) <= maxlen) {
		rfname = fname;
		printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));
		printf("Result:   '%s', length: %ld chars\n", rfname, strlen(rfname));
		return;
	}

	/*
	 * max chars to be displayed +1x '\0' + 1x'#' + 2x ' ', at both ends of dots ...
	 */
	rfname = calloc((maxlen + 1 + 3 + 2), sizeof(char));
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

	printf("Original: '%s', length: %ld chars\n", fname, strlen(fname));
	printf("Result:   '%s', length: %ld chars\n", rfname, strlen(rfname));
	free(rfname);
}

