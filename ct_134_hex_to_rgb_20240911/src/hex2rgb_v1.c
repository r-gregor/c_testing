/*
 * hex2rgb_v1.c
 * 20240909 v1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv) {

	if (argc != 2) {
		printf("Must supply a hex nzmber in form: AABBCC\n");
		return EXIT_FAILURE;
	}

	char *str = "cAd9aF";
	int r, g, b;
	sscanf(str, "%02x%02x%02x", &r, &g, &b);

	printf("R: %d\nG: %d\nB: %d\n", r, g, b);
	printf("RGB: %d;%d;%d\n", r, g, b);



	return 0;
}

