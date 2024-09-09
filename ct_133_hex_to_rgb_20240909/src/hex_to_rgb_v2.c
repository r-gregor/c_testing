/*
 * hex_to_rgb.c
 * 20240909 v2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool is_hexn(int n);

/* main */
int main(void) {

	char str[7] = {0};
	int r, g, b;


	printf("Enter hex number in form \"FFAACC\":  ");
	if(fgets(str, 7, stdin) != NULL) {
		sscanf(str, "%02x%02x%02x", &r, &g, &b);

		/*
		if (!is_hexn(r) || !is_hexn(g) || !is_hexn(b)) {
			printf("Value entered is not valid hex number\n");
			return EXIT_FAILURE;
		}
		*/

		printf("R: %d\nG: %d\nB: %d\n", r, g, b);
		printf("RGB: %d;%d;%d\n", r, g, b);
	} else {
		printf("Something went wrong");
		return EXIT_FAILURE;
	}

	return 0;
} /* end main */

bool is_hexn(int n) {
	if (n < 0 || n > 255) {
		return false;
	}
	return true;
}

