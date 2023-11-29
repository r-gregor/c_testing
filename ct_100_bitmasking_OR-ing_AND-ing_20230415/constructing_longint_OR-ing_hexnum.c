#include <stdio.h>
#include <stdint.h>

// delimiter
void crt() {
	printf("---\n");
}

/**
 * MAIN
 */
int main() {

	printf("Constructing, OR-ing parts of 32bit integer (8bit hex: RR GG BB AA)\n");
	printf("unsigned int colour = 0xFF | (0x00 << 8) | (0xCC << 16) | (0xFF << 24);\n");
	unsigned int colour = 0xFF | (0x00 << 8) | (0xCC << 16) | (0xFF << 24);
	printf("Color in HEX: %x\n", colour);

	crt();

	printf("Extracting middle (16bit offset) -- shifting 16 bits right and\n");
	printf("AND-ing it with 0xFF (1111 1111):\n");
	printf("long int middle = (colour >> 16) & 0xFF;\n");
	long int middle = (colour >> 16) & 0xFF;
	printf("Middle in HEX: %lx\n", middle);
	printf("Middle in DEC: %ld (12*16 + 12)\n", middle);

	crt();

	printf("long int num2 = 0x00000000;\n");
	printf("num2 |= 0x000000FF;");
	long int num2 = 0x00000000;
	num2 |= 0x000000FF;
	printf(" ==> Result HEX / DEC: %08lx / %11ld\n", num2, num2);
	
	printf("num2 |= 0x0000FF00;");
	num2 |= 0x0000FF00;
	printf(" ==> Result HEX / DEC: %08lx / %11ld\n", num2, num2);

	printf("num2 |= 0x00FF0000;");
	num2 |= 0x00FF0000;
	printf(" ==> Result HEX / DEC: %08lx / %11ld\n", num2, num2);
	
	printf("num2 |= 0xFF000000;");
	num2 |= 0xFF000000;
	printf(" ==> Result HEX / DEC: %08lx / %11ld\n", num2, num2);


	return 0;
} // end MAIN

