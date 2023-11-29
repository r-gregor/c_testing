#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex_to_bin.h"
#define MAX_BITS 64
#define MAX_HEX_DIGITS (MAX_BITS/4)

/**
 * V2
 */
int main(int argc, char **argv) {


	char *hex_v = malloc(sizeof(char) * (MAX_HEX_DIGITS + 1));
	if (argc == 2) {
		if (strlen(argv[1]) > MAX_HEX_DIGITS) {
			printf("Only %d-digit hex numbers allowed ... truncating digits past %d-th digit.\n", MAX_HEX_DIGITS, MAX_HEX_DIGITS);
		}
		strncpy(hex_v, argv[1], MAX_HEX_DIGITS);
		hex_v[MAX_HEX_DIGITS] = '\0';                 // NEEDED after strncpy
	} else {
		strcpy(hex_v, "AABBCCDDEEFF0011");
		// hex_v[MAX_HEX_DIGITS] = '\0';              // not needed - strcpy copies over '\0' !
	}

	char bin_v[256];                                  // first char must be set zo '\0' because strcat() in 'hex_to_bin.h' replaces last '\0'
    bin_v[0] = '\0';                                  // of previous string with first char of concatenated string!
	char *newhex = hex_v;
	
	HexToBin64(newhex, bin_v);                        // converting hex to bin into bin_v
	printf("hex num 0x%s in binary:\n%s\n", hex_v, bin_v);
	free(newhex);
	newhex = NULL;
	hex_v = NULL;

	return 0;
}
