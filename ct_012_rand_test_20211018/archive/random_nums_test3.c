#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLUMNS 4
#define MAX_LINES 25

/*
 * V3
 */

int maxdigits = 1e7;
int num_columns;


int main(int argc, char *argv[]) {

	srand(time(0));

	if (argc == 2) {
		num_columns = atoi(argv[1]);
	} else {
		num_columns = MAX_COLUMNS;
	}

int count = 1;
char lineend;
	for (int i=0; i<MAX_LINES; i++) {

		if (count % num_columns == 0) {
			lineend = '\n';
		} else {
			lineend = '\0';
		}
		printf("Rand num %-3d:%-15d%c", count, rand() % maxdigits, lineend);
		count++;
	}

	printf("\n");


	return 0;
}

