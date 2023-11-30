#include <stdio.h>
#include <stdlib.h>
#define MAX_COLUMNS 4

int maxdigits = 1e7;
int main() {

int count = 1;
	for (int i=0; i<25; i++) {

		if (count % MAX_COLUMNS == 0) {
			printf("Rand num %-3d:%-15d\n", count, rand() % maxdigits);
			count++;
		} else {
			printf("Rand num %-3d:%-15d", count, rand() % maxdigits);
			count++;
		}
	}

	printf("\n");


	return 0;
}
