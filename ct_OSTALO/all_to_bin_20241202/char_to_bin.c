#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	char c;
	if (argc == 2) {
		c = *(argv[1]);
	} else {
		c = 'a';
	}

	int mask = 0b10000000;

	for (int i=0; i <= 7; i++) {
		printf("%c", c & mask ? '1' : '0');
		mask >>= 1;
	}
	printf("\nchar '%c' is %d\n", c, c);

	return 0;
}

