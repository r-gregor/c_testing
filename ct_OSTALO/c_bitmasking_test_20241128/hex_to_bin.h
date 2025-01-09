#ifndef _HEX_TO_BIN_H_
#define _HEX_TO_BIN_H_

#include <stdio.h>
#include <string.h>

/**
 * V2
 */
// void HexToBin(char* hexdec, char *bin, int bits);
void HexToBin(char* hexdec, char *bin);
// void HexToBin32(char* hexdec, char *bin);
// void HexToBin64(char* hexdec, char *bin);

// function to convert Hexadecimal to Binary Number and display it
// from: https://www.geeksforgeeks.org/program-to-convert-hexadecimal-number-to-binary
void HexToBin(char* hexdec, char *bin_v) {
	
	long int i = 0;
 
	while (hexdec[i]) {
 
		switch (hexdec[i]) {
		case '0':
			strcat(bin_v, "0000 ");
			break;
		case '1':
			strcat(bin_v, "0001 ");
			break;
		case '2':
			strcat(bin_v, "0010 ");
			break;
		case '3':
			strcat(bin_v, "0011 ");
			break;
		case '4':
			strcat(bin_v, "0100 ");
			break;
		case '5':
			strcat(bin_v, "0101 ");
			break;
		case '6':
			strcat(bin_v, "0110 ");
			break;
		case '7':
			strcat(bin_v, "0111 ");
			break;
		case '8':
			strcat(bin_v, "1000 ");
			break;
		case '9':
			strcat(bin_v, "1001 ");
			break;
		case 'A':
		case 'a':
			strcat(bin_v, "1010 ");
			break;
		case 'B':
		case 'b':
			strcat(bin_v, "1011 ");
			break;
		case 'C':
		case 'c':
			strcat(bin_v, "1100 ");
			break;
		case 'D':
		case 'd':
			strcat(bin_v, "1101 ");
			break;
		case 'E':
		case 'e':
			strcat(bin_v, "1110 ");
			break;
		case 'F':
		case 'f':
			strcat(bin_v, "1111 ");
			break;
		default:
			printf("\nInvalid hexadecimal digit %c\n", hexdec[i]);
		}
		i++;
	}
	// printf("\n");
}

/*
void HexToBin32(char* hexdec, char *bin_v) {
	HexToBin(hexdec, bin_v, 32);
}

void HexToBin64(char* hexdec, char *bin_v) {
	HexToBin(hexdec, bin_v, 64);
}
*/

#endif

