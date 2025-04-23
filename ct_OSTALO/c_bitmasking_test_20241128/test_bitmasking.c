#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hex_to_bin.h"


int main(void) {

	uint32_t fst = 0xf;
	uint32_t snd = 0xff;
	uint32_t trd = 0xfff;
	uint32_t frt = 0xffff;

	char hex_fst[33];
	char hex_snd[33];
	char hex_trd[33];
	char hex_frt[33];

	char bin_fst[33];
	char bin_snd[33];
	char bin_trd[33];
	char bin_frt[33];

	printf("uint32_t fst = %d\n", fst);
	printf("uint32_t snd = %d\n", snd);
	printf("uint32_t trd = %d\n", trd);
	printf("uint32_t frt = %d\n", frt);

#if 1
	sprintf(hex_fst, "%x", fst);
	sprintf(hex_snd, "%x", snd);
	sprintf(hex_trd, "%x", trd);
	sprintf(hex_frt, "%x", frt);

	HexToBin(hex_fst, bin_fst);
	HexToBin(hex_snd, bin_snd);
	HexToBin(hex_trd, bin_trd);
	HexToBin(hex_frt, bin_frt);

	printf("--------------------------------------------\n");
	printf("uint32_t fst = %s\n", bin_fst);
	printf("uint32_t snd = %s\n", bin_snd);
	printf("uint32_t trd = %s\n", bin_trd);
	printf("uint32_t frt = %s\n", bin_frt);
# endif

	return 0;
}
