#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex_to_bin.h"

/**
 * V1
 */
int main(int argc, char **argv) {


	char *hex_v = malloc(sizeof(char) * 17);
	if (argc == 2) {
		strncpy(hex_v, argv[1], 16);  // ESSENTIAL, otherways: buffer overflow!!
		hex_v[16] = '\0';             // NEEDED after atrncpy !!
	} else {
		strcpy(hex_v, "AABBCCDDEEFF0012");
	}

	char bin_v[256];                 // first char must be set zo '\0' because strcat() replaces last '\0'
    bin_v[0] = '\0';                 // of previous string with first char of concatenated string!
	char *newhex = hex_v;
	
	HexToBin64(newhex, bin_v);          // converting hex to bin into bin_v
	printf("hex num 0x%s in binary:\n%s\n", hex_v, bin_v);
	free(newhex);
	newhex = NULL;

	return 0;
}
