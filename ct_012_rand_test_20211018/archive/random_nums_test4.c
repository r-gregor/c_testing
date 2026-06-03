#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLUMNS 4
#define MAX_LINES 25

/*
 * V4
 */

void clr() {
	system("@cls||clear");
}

int maxdigits = 1e7;
int num_columns;

void usage(char *[]);

int main(int argc, char *argv[]) {
	
	clr();
	printf("\n");

	if (argc < 2) {
		printf("Default number of columns: %d\n", MAX_COLUMNS);
		printf("To display different number of columns do:\n");
		usage(argv);
	} 

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

void usage(char *arg[]) {
	printf(	"Usage: "
			"\t%s <number of columns>\n", arg[0]);
	printf("\n");
}

