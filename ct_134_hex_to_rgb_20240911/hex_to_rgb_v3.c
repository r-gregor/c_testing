/*
 * hex_to_rgb.c
 * 20240909 v3
 * 20240911 v3
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* main */
int main(int argc, char **argv) {


	if (argc != 2 || strlen(argv[1]) != 6) {
		printf("[ERROR] must supply a valid color hex number like \"aabbff\"\n");
		return EXIT_FAILURE;
	}

	int r, g, b;
	for (size_t i =0; i < strlen(argv[1]); i++) {
		if (!isxdigit((int)argv[1][i])) {
			printf("[ERROR] '%s' is NOT a valid hex number\n", argv[1]);
			return EXIT_FAILURE;
		}
	}

	sscanf(argv[1], "%02x%02x%02x", &r, &g, &b);
	printf("R: %d\nG: %d\nB: %d\n", r, g, b);
	printf("RGB: %d;%d;%d\n", r, g, b);

	return 0;
} /* end main */

