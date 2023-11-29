/*
 * bitmasking4.c
 */

#include <stdio.h>
#include <string.h>


// void displayHexToBin(char* hexdec);
void HexToBin(char* hexdec, char *bin);

int main(int argc, char **argv) {

	int hex_v = 0x04030201;          // 32 bit number (in hex)
	char bin_v[33];                  // first char must be set zo '\0' because strcat() replaces last '\0'
    bin_v[0] = '\0';                 // of previous string with first char of concatenated string!
	HexToBin("04030201", bin_v);     // converting hex to bin into bin_v

	printf("Initial value of 0x04030201 in HEX is: %x\n", hex_v);
	printf("Initial value of 0x04030201 in DEC is: %d\n", hex_v);
	printf("Initial value of 0x04030201 in BIN is: %s\n", bin_v);
	
	// extracting each Byte ftom value from MSB to LSB
	int a = (hex_v >> 24) & 0xff;  // 04 (bits 24-31) MSB
	int b = (hex_v >> 16) & 0xff;  // 03 (bits 16-23)
	int c = (hex_v >>  8) & 0xff;  // 02 (bits 08-15)
	int d = hex_v         & 0xff;  // 01 (bits 00-07) LSB

	printf("Extracting each Byte of 'value' from MSB to LSB:\n");
	printf("a = %x\n", a);
	printf("b = %x\n", b);
	printf("c = %x\n", c);
	printf("d = %x\n", d);

	return 0;
}

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

