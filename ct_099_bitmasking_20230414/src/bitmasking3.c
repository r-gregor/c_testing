/*
 * bitmasking3.c
 */

#include <stdio.h>
#include <string.h>


void displayHexToBin(char* hexdec);

int main(int argc, char **argv) {

	int hex_v = 0x04030201;        // 32 bit number
	
	printf("Initial value of 0x04030201 in HEX is: %x\n", hex_v);
	printf("Initial value of 0x04030201 in DEC is: %d\n", hex_v);
	printf("Initial value of 0x04030201 in BIN is: ");
	displayHexToBin("04030201");
	
	// extracting each Byte ftom hex_v from MSB to LSB
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

// function to convert Hexadecimal to Binary Number
// from: https://www.geeksforgeeks.org/program-to-convert-hexadecimal-number-to-binary
void displayHexToBin(char* hexdec) {
 
	long int i = 0;
 
	while (hexdec[i]) {
 
		switch (hexdec[i]) {
		case '0':
			printf("0000 ");
			break;
		case '1':
			printf("0001 ");
			break;
		case '2':
			printf("0010 ");
			break;
		case '3':
			printf("0011 ");
			break;
		case '4':
			printf("0100 ");
			break;
		case '5':
			printf("0101 ");
			break;
		case '6':
			printf("0110 ");
			break;
		case '7':
			printf("0111 ");
			break;
		case '8':
			printf("1000 ");
			break;
		case '9':
			printf("1001 ");
			break;
		case 'A':
		case 'a':
			printf("1010 ");
			break;
		case 'B':
		case 'b':
			printf("1011 ");
			break;
		case 'C':
		case 'c':
			printf("1100 ");
			break;
		case 'D':
		case 'd':
			printf("1101 ");
			break;
		case 'E':
		case 'e':
			printf("1110 ");
			break;
		case 'F':
		case 'f':
			printf("1111 ");
			break;
		default:
			printf("\nInvalid hexadecimal digit %c",
				   hexdec[i]);
		}
		i++;
	}
	printf("\n");
}

