#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	int c;
	if (argc == 2) {
		c = atoi(argv[1]);
	} else {
		c = 255;
	}

	if (c > 255) {
		printf("Nuber mast be lower than 256! Try again.\n");
		return -1;
	}

	int mask = 0b10000000;

	printf("%d is: ", c);
	for (int i=0; i <= 7; i++) {
		printf("%c", c & mask ? '1' : '0');
		mask >>= 1;
	}
	printf("\n");

	return 0;
}

