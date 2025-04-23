/*
 * substring_withpointers_v3.c
 * 20240312_1_en
 * 20240312_2_en v2: updated to use widechars (UTF-8)
 * 20240313_3_mdb
 * 20240313_3_en
 * 20240313_4_en v3: accept user parameters
 *                   usage function
 *
 */
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <libgen.h>

#define SUBS_MIN_LEN 3

void show_start_end(const size_t begin, const size_t subss_len);
void print_substring(const wchar_t *start, const wchar_t *end);
void usage(char *progname);


/* MAIN */
int main(int argc, char **argv) {

	setlocale(LC_ALL, "C.UTF-8");

	if(argc != 3) {
		usage(argv[0]);
		return -1;
	}

	const size_t begin     = atoi(argv[1]);     // start char
	const size_t subss_len = atoi(argv[2]);     // substring length
	
	if(subss_len < SUBS_MIN_LEN) {
		printf("[ERROR] Length of substring should be at least %d or more\n", SUBS_MIN_LEN);
		return -1;
	}

	printf("Get substring with start at %ld-th char and length of %ld chars:\n\n", begin, subss_len);

	const wchar_t *str = L"Iz česa je lepota tvoja stkana, da tvoj obraz milijon podob ima?";
	printf("'%ls' -- original\n", str);

	const size_t strl = wcslen(str);
	const wchar_t *start        = str   + begin - 1;
	const wchar_t *end          = start + subss_len;
	const size_t abs_len        = end - str;

	if (subss_len <= 0) {
		printf("[ERROR] Substring of length 0, or less\n");
		return -1;
	}

	if (abs_len > strl || begin > strl || begin <= 0) {
		printf("[ERROR] Substring out of original boundaries\n");
		return -1;
	}

	show_start_end(begin, subss_len);

	for(int i = 0; i < begin - 1; ++i) printf(" "); // begin - 1 becaise of "'" char
	print_substring(start, end);

	return 0;
} /* end MAIN */


/*
 * display beginiing and end of
 * substring on original string
 * @param begin:        start of subatring
 * @param subss_len:    length of substring (including first char at start)
 */
void show_start_end(const size_t begin, const size_t subss_len) {
	int st;
	if(begin != 1) {
		printf(" |"); // leading space for "'" character
		for (st=0; st < begin - 2; ++st) {
			printf(" ");
		}
	} else {
		printf(" ");
	}
	printf("|");
	for (st=1; st < subss_len - 1; ++st) {
		printf(" ");
	}
	printf("|\n");

	if(begin != 1) {
		printf(" 1"); // 1-st character + leading space for "'" character
		for (st=0; st < begin - 2; ++st) {
			printf(" ");
		}
	} else {
		printf(" ");
	}
	printf("%ld", begin);

	size_t sd;
	sd = (begin < 10)? 1: 2;
	for (st=1; st < subss_len - sd; ++st) {
		printf(" ");
	}
	printf("%ld\n\n", begin - 1 + subss_len);
}


/*
 * display substring
 */
void print_substring(const wchar_t *start, const wchar_t *end) {
	printf("'");
	size_t k=0;
	while (start + k < end) {
		printf("%lc", *(start + k));
		k++;
	}
	printf("' -- substring\n");
 }

void usage(char *progname) {
	printf("\n\tUsage: "
			"%s <start_pos> <subss_len>\n"
			"\t\tstart_pos  ... [int], beginning position of substring\n"
			"\t\tsubss_len  ... [int], length of substring (at least %d chars)\n\n", basename(progname), SUBS_MIN_LEN
	);
}
