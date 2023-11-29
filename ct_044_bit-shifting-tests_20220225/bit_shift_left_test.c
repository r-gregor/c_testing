#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define NUM_SHIFTS 31

/**
 * from: https://www.youtube.com/watch?v=lvjW-aUcbF0
 */

int main(int argc, char **argv) {

	unsigned long int a = 5;

	printf("Original value of a = %ld ...\n\n", a);
	printf("%-15s%11s%17s\n", "Left shifted by", "Hex", "Dec");
	for (int j=0; j<(15+11+17); j++) {
		printf("-");
	}
	printf("\n");

	int i;
	for (i=0; i < NUM_SHIFTS + 1 ; i++) {
		printf("%15d   %08lx%17lu\n", i, a << i, a << i);
	}


	return 0;
}
