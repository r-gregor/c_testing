/*
 * bitmasking1.c
 */

#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	char c;
	int mask;

	c = 'A';
	mask = 0b10000000;

	for (int i=0; i<=7; i++) {
		printf("%c", c & mask ? '1' : '0');
		mask >>= 1;
	}

	printf("\nc'%c' is %d\n", c, c);


	return 0;
}

