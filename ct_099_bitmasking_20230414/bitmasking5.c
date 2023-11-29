/*
 * bitmasking5.c
 */

#include <stdio.h>
#include <string.h>

void extractBytesFromHex(int hex_v);
void extractBytesFromHexNoMasking(int hex_v);
void HexToBin(char* hexdec, char *bin);

/**
 * MAIN
 */
int main(int argc, char **argv) {

	int hex_v = 0x04030201;          // 32 bit number (in hex)
	char bin_v[33];                  // first char must be set zo '\0' because strcat() replaces last '\0'
    bin_v[0] = '\0';                 // of previous string with first char of concatenated string!
	HexToBin("04030201", bin_v);     // converting hex to bin into bin_v

	printf("value = '0x04030201'\n");
	printf("Value of 0x04030201 in HEX: '%x'\n", hex_v);  // 4030201 
	printf("Value of 0x04030201 in DEC: '%d'\n", hex_v);  // 67305985
	printf("Value of 0x04030201 in BIN: '%s'\n", bin_v);  // 0000 0100 0000 0011 0000 0010 0000 0001
	
	printf("---\n");

	printf("Extracting Bytes from HEX with bit masking:\n");
	extractBytesFromHex(hex_v);

	printf("---\n");

	printf("Extracting Bytes from HEX without bit masking:\n");
	extractBytesFromHexNoMasking(hex_v);

	return 0;
} // end MAIN

// function to convert Hexadecimal to Binary Number and display it
// from: https://www.geeksforgeeks.org/program-to-convert-hexadecimal-number-to-binary
// void displayHexToBin(char* hexdec) {
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
			printf("\nInvalid hexadecimal digit %c",
				   hexdec[i]);
		}
		i++;
	}
	// printf("\n");
}


void extractBytesFromHex(int hex_v) {
	
	// extracting each Byte ftom value from MSB to LSB
	//                                                         4         3         2         1
	//                                                     +-------+ +-------+ +-------+ +-------+
	//                                                     0000 0100 0000 0011 0000 0010 0000 0001
	//
	int a = (hex_v >> 24) & 0xff;  // 04 (bits 24-31) MSB  0000 0100
	int b = (hex_v >> 16) & 0xff;  // 03 (bits 16-23)                0000 0011
	int c = (hex_v >>  8) & 0xff;  // 02 (bits 08-15)                          0000 0010
	int d = hex_v         & 0xff;  // 01 (bits 00-07) LSB                                0000 0001

	printf("Extracting each Byte of 'value' from MSB to LSB:\n");
	printf("a = %x\n", a);
	printf("b = %x\n", b);
	printf("c = %x\n", c);
	printf("d = %x\n", d);

	// output:
	// a = 4
	// b = 3
	// c = 2
	// d = 1
}


void extractBytesFromHexNoMasking(int hex_v) {
	
	// extracting each Byte ftom value from MSB to LSB
	//                                                         4         3         2         1
	//                                                     +-------+ +-------+ +-------+ +-------+
	//                                                     0000 0100 0000 0011 0000 0010 0000 0001
	//
	int a = (hex_v >> 24);  // 04       (bits 24-31) MSB   0000 0100
	int b = (hex_v >> 16);  // 0403     (bits 16-31)       0000 0100 0000 0011
	int c = (hex_v >>  8);  // 040302   (bits 08-31)       0000 0100 0000 0011 0000 0010
	int d = hex_v        ;  // 04030201 (bits 00-31) LSB   0000 0100 0000 0011 0000 0010 0000 0001

	printf("Extracting each Byte of 'value' from MSB to LSB:\n");
	printf("a = %x\n", a);
	printf("b = %x\n", b);
	printf("c = %x\n", c);
	printf("d = %x\n", d);

	// output:
	// a = 4
	// b = 403
	// c = 40302
	// d = 4030201
}

