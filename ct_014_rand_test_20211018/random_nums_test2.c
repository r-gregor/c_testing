#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLUMNS 4
#define MAX_LINES 25

int maxdigits = 1e7;
int num_columns;


/** main */
int main(int argc, char *argv[]) {

	if (argc == 2) {
		num_columns = atoi(argv[1]);
	} else {
		num_columns = MAX_COLUMNS;
	}

int count = 1;
	for (int i=0; i<MAX_LINES; i++) {

		if (count % num_columns == 0) {
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
