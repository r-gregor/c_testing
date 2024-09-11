/*
 * check_for_hex_digits_v3.c
 * 20240911 v3: changed return value of wrong_color_num_len() to 'bool'
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define COLOR_HEX_NUM_LEN 6

bool wrong_color_num_len(char *num);
int chk_hex_isxdigit(char *);
int chk_hex_strspn(char *num, char *hexdigits);

/* main */
int main(void) {

	char color1[] = "AAb7C2";   // ok
	char color2[] = "a9BbCC6f"; // to many digits
	char color3[] = "A0BBxC";   // digit outside hex range

	char hex_digits[] = "0123456789abcdefABCDEF";

	printf("Checking if color hex code (6 digits) is valid hex nubmber.\n");
	printf("Test numbers:\n");
	printf("color1: AAb7C2     -- ok\n");
	printf("color2: a9BbCC6f   -- to many digits\n");
	printf("color3: A0BBxC     -- digit 'x' outside hex range\n");
	printf("---\n");

	printf("Check 1: using 'int isxdigit(int c)' from 'ctype.h'\n");
	chk_hex_isxdigit(color1);
	chk_hex_isxdigit(color2);
	chk_hex_isxdigit(color3);

	printf("---\n");

	printf("Check 2: using 'size_t strspn(const char *s1, const char *s)' from 'string.h'\n");
	chk_hex_strspn(color1, hex_digits);
	chk_hex_strspn(color2, hex_digits);
	chk_hex_strspn(color3, hex_digits);

	printf("---\n");

	return 0;
} /* end main */


/* =============== functions definitions ============= */

/* check for color num length */
bool wrong_color_num_len(char *num) {
	size_t num_len = strlen(num);
	if(num_len != COLOR_HEX_NUM_LEN) {
		printf("[ERR] %-10s is NOT of required %d digits length\n", num, COLOR_HEX_NUM_LEN);
		return true;
	}
	return false;
}

/* check if hex number using isxdigit() */
int chk_hex_isxdigit(char *num) {
	if(wrong_color_num_len(num)) return EXIT_FAILURE;

	for (size_t i =0; i < strlen(num); i++) {
		if (!isxdigit((int)num[i])) {
			printf("[ERR] %-10s is NOT a valid hex number\n", num);
			return EXIT_FAILURE;
		}
	}
	
	printf("[INF] %-10s is a valid hex number\n", num);
	return EXIT_SUCCESS;
}

/* check if hex number using strspn() */
int chk_hex_strspn(char *num, char *hexdigits) {
	if(wrong_color_num_len(num)) return EXIT_FAILURE;

	if(strspn(num, hexdigits) != strlen(num)) {
		printf("[ERR] %-10s is NOT a valid hex number\n", num);
	} else {
		printf("[INF] %-10s is a valid hex number\n", num);
	}
	return EXIT_SUCCESS;
}

