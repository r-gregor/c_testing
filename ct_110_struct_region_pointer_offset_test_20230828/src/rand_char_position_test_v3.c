/*
 * v3
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINE_LEN 32
#define EMPTY_SPOT '.'

/* Main */
int main(int argc, char **argv) {

	srand(time(0));
	int line_start = 0;

	char name[] = "GREGOR REDELONGHI";
	size_t name_len = sizeof(name) - 1;

 	for (int i=0, n=0; i < name_len; i++) {
		int curr_pos = line_start + rand() % LINE_LEN;
		for (int j=0; j < LINE_LEN; j++) {
			if (j == curr_pos) {
				if (name[n] == ' ') {
					printf("%2c", EMPTY_SPOT);
				} else {
					printf("%2c", name[n]);
				}
				n++;
			} else {
				printf("%2c", EMPTY_SPOT);
			}
		}
		printf("\n");
	}

	return 0;
} // end Main

