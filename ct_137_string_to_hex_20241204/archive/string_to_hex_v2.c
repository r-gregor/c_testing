/*
 * string_to_hex.c
 * v1: 20241202 en
 * v2: 20241202 en: move conversion logic into function
 *
 */
#include <stdio.h>
#include <string.h>

char *get_hex_from_string(char *str);


int main(int argc, char **argv) {

	char name[64]  = {0};
	
	if (argc == 2) {
		strcpy(name, argv[1]);
	} else {
		strcpy(name, "rgregor");
	}

	get_hex_from_string(name);


	return 0;
}

char *get_hex_from_string(char *str) {
	size_t str_len = strlen(str);

	printf("'%s' in hex: ", str);
	for (int i = 0; i < str_len; i++) {
		char letter=str[i];
		printf("%x", letter);
	}
	printf("\n");

	return str;
}
