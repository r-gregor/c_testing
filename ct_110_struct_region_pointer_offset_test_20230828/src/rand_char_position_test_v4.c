/*
 * v4
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINE_LEN 32
#define LINES_NUM 32
#define EMPTY_SPOT '.'

void print_name(char *name, int n);

/* Main */
int main(int argc, char **argv) {

	srand(time(0));
	int line_start = 0;

	char name[] = "GREGOR REDELONGHI";

	int n = 0;
 	for (int i=0; i < LINES_NUM; i++) {
		int curr_pos = line_start + rand() % LINE_LEN;
		for (int j=0; j < LINE_LEN; j++) {
			if (j == curr_pos) {
				print_name(name, n);
				n++;
			} else {
				printf("%2c ", EMPTY_SPOT);
			}
		}
		printf("\n");
	}

	return 0;
} // end Main

void print_name(char *name, int n) {
	if (n < strlen(name)) {
		if (name[n] == ' ') {
			printf("%2c ", EMPTY_SPOT);
		} else {
			printf("%2c ", name[n]);
		}
	} else {
		printf("%2c ", EMPTY_SPOT);
	}
}

