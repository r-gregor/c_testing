/*
 * substring_withpointers_v1.c
 * v1
 * 20240312_v1_en
 */
#include <stdio.h>
#include <string.h>

void show_start_end(const size_t begin, const size_t subss_len);
void print_substring(const char *start, const char *end);

/* MAIN */
int main(void) {
	const size_t begin  = 12;        // strat char
	const size_t subss_len = 16;     // substring length
	
	printf("Get substring with start at %ld-th char and end length of %ld chars:\n\n", begin, subss_len);

	const char *str = "Iz cesa je lepota tvoja stkana, da tvoj obraz milijon podob ima?"; // WITHOUT MULTIBYTES CHARS !!
	printf("'%s' -- original\n", str);

	const size_t strl = strlen(str);
	const char *start        = str   + begin - 1;
	const char *end          = start + subss_len;
	const size_t len_diff    = end - start;

	if (subss_len <= 0) {
		printf("[ERROR] Substring of length 0, or less\n");
		return -1;
	}

	if (len_diff > strl || begin > strl) {
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
 */
void show_start_end(const size_t begin, const size_t subss_len) {
	int st;
	printf(" |"); // leading space for "'" character
	for (st=0; st < begin - 2; ++st) {
		printf(" ");
	}
	printf("|");
	for (st=1; st < subss_len - 1; ++st) {
		printf(" ");
	}
	printf("|\n");

	printf(" 1"); // 1-st character + leading space for "'" character
	for (st=0; st < begin - 2; ++st) {
		printf(" ");
	}
	printf("%ld", begin);

	for (st=1; st < subss_len - 2; ++st) {
		printf(" ");
	}
	printf("%ld\n\n", begin - 1 + subss_len);
}


/*
 * display substring
 */
void print_substring(const char *start, const char *end) {
	printf("'");
	size_t k=0;
	while (start + k < end) {
		printf("%c", *(start + k));
		k++;
	}
	printf("' -- substring\n");
}

