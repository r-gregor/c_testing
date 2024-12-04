/* string_to_hex.c
 * v1: 20241202 en
 * v2: 20241202 en: move conversion logic into function
 * v3: 20241202 en: function returns a hex string
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 64

int get_hex_from_string(char *str, char *hex_str);

/* main */
int main(int argc, char **argv) {

	char name[MAX_STR_LEN]   = {0};
	char hexstr[256] = {0};
	
	if (argc == 2) {
		strcpy(name, argv[1]);
	} else {
		printf("Usage: \n\t%s \"<string>\"\n\n", argv[0]);
		strcpy(name, "rgregor");
	}

	if (get_hex_from_string(name, hexstr) < 0) {
		return -1;
	}

	printf("'%s' in hex: %s\n", name, hexstr);

	return 0;
} /* end main */


/* function definitions */
int get_hex_from_string(char *str, char *hex_str) {
	size_t str_len = strlen(str);

	if (str_len >= MAX_STR_LEN) {
		fprintf(stderr, "[ERROR] String to long\n");
		return -1;
	}

	char singlech[3] = {0};
	for (int i = 0; i < str_len; i++) {
		sprintf(singlech, "%x", str[i]);
		strcat(hex_str, singlech);
	}

	return 1;
}

