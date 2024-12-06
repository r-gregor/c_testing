/* string_to_hex.c
 * v1: 20241202 en
 * v2: 20241202 en: move conversion logic into function
 * v3: 20241202 en: function returns exit status
 * v4: 20241206 en: return codes for function
 */
#include <stdio.h>
#include <string.h>
// #include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_LEN 64
#define MAX_XSTR_LEN 256

#define FUNC_SUCCESS 1
#define FUNC_ERROR   0

int get_hex_from_string(char *str, char *hex_str);

/* main */
int main(int argc, char **argv) {

	char name[MAX_STR_LEN]    = {0};
	char hexstr[MAX_XSTR_LEN] = {0};
	
	if (argc == 2) {
		strcpy(name, argv[1]);
	} else {
		printf("Usage: \n\t%s \"<string>\"\n\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (!get_hex_from_string(name, hexstr)) {
		return EXIT_FAILURE;
	}

	printf("'%s' in hex: 0x%s\n", name, hexstr);

	return EXIT_SUCCESS;
} /* end main */


/* function definitions */
int get_hex_from_string(char *str, char *hex_str) {
	size_t str_len = strlen(str);

	if (str_len >= MAX_STR_LEN) {
		fprintf(stderr, "[ERROR] String to long\n");
		return FUNC_ERROR;
	}

	char singlech[3] = {0};
	for (int i = 0; i < str_len; i++) {
		sprintf(singlech, "%x", str[i]);
		strcat(hex_str, singlech);
	}

	return FUNC_SUCCESS;
}

