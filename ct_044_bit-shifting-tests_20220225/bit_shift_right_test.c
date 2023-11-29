#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define NUM_SHIFTS 38

/**
 * from: https://www.youtube.com/watch?v=lvjW-aUcbF0
 */

int main(int argc, char **argv) {

	unsigned long int a = 100000000000;

	printf("Original value of a = %ld ...\n\n", a);
	printf("%-16s%14s%15s\n", "Right shifted by", "Hex", "Dec");
	for (int j=0; j<(16+14+15); j++) {
		printf("-");
	}
	printf("\n");

	int i;
	for (i=0; i < NUM_SHIFTS + 1 ; i++) {
		printf("%16d   %011lx%15lu\n", i, a >> i, a >> i);
	}


	return 0;
}
