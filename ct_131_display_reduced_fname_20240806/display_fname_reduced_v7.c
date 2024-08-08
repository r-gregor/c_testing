/*
 * display_fname_reduced_v7.c
 * 20240806_01_en -- v1
 * 20240806_02_en -- v2: put base logic into function display_fname_reduced()
 * 20240806_03_en -- v3: multiple filenames
 * 20240806_04_en -- v4: sep_char = 'string'
 * 20240806_05_en -- v5: rdc_fname from malloc-ed to pointer to buffer
 * 20240806_06_en -- v6: getting rid of MAX_CHARS
 *                       check for minimal filename length, accept as comman argument
 * 20240808_07_en -- v7: divide display_reduced() function into separate functions
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LAST_CHARS 13 // '_' + tomestamp + '.txt'

void display_reduced(char *original, size_t maxlen, char *sep_char);
size_t get_rdc_fname_length(int argc, char **argv);
char *get_reduced_filename(char *original, size_t maxlen, char *sep_char);
void printout(char *original, char *reduced);

/* MAIN */
int main(int argc, char **argv) {

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

	/* v7 */
	size_t rdc_fname_len = get_rdc_fname_length(argc, argv);

	char *sep_char = "~";
	printf("\nSeparation character: '%s'\n", sep_char);
	printf("Reducing file names to maximum length of %ld characters:\n\n", rdc_fname_len);
	for (int i = 0; i < fnames_num; i++) {
		display_reduced(fnames[i], rdc_fname_len, sep_char);
		printf("---\n");
	}

	return 0;
} /* end MAIN */


/*
 * v7
 * get reduced fname string and printout original and reduced fname
 */
void display_reduced(char *original, size_t maxlen, char *sep_char) {
	char *reduced = get_reduced_filename(original, maxlen, sep_char);
	printf("Original: '%s', length: %ld chars\n", original, strlen(original));
	printf("Result:   '%s', length: %ld chars\n", reduced, strlen(reduced));
}


/*
 * v7
 * Get desired reduced fname length as command parameter. If not given
 * set the value to 25. Return reduced fname length.
 * lowest size limited by MIN_LEN
 */
size_t get_rdc_fname_length(int argc, char **argv) {

#define MIN_LEN 20
size_t result = 0;

	if (argc == 2) {
		result = atoi(argv[1]);
		printf("Setting filename length to %ld characters ...\n", result);
	} else {
		printf("No desired filename length given. Setting to 25 characters ...\n");
		result = 25;
	}

	if (result < MIN_LEN) {
		printf("Minimal filename length: 20 characters. Correcting ...\n");
		result = MIN_LEN;
	}

	return result;
}


/*
 * return reduced fname string as char *
 */
char *get_reduced_filename(char *original, size_t maxlen, char *sep_char) {

	char *fname = original;
	char *rdc_fname = NULL;

	size_t sepc_len = strlen(sep_char);
	size_t buff_size = maxlen + sepc_len + 1;
	char buffer[buff_size];

	if (strlen(fname) <= maxlen) {
		rdc_fname = fname;
		return rdc_fname;
	}

	/* else ... */
	rdc_fname = buffer;

	int pos = 0;
	int first_part = maxlen - LAST_CHARS - sepc_len;
	while (pos < first_part) {
		rdc_fname[pos] = fname[pos];
		pos++;
	}

	for (int k = 0; k < sepc_len; k++) {
		rdc_fname[pos++] = sep_char[k];
	}

	/* v6 */
	int last = LAST_CHARS;
	while (last >= 0) {
		rdc_fname[pos] = fname[strlen(fname) - last];
		pos++;
		last--;
	}

	return rdc_fname;
}

