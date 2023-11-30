/*
 * v2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINE_LEN 32
#define EMPTY_SPOT '.'

int main(int argc, char **argv) {

	srand(time(0));
	int line_start = 0;

#if 0
	for (int i=0; i < 10; i++) {
			int line_end = line_start + LINE_LEN - 1;
			printf("line start: %d, line end: %d, current offset: %d\n", line_start, line_end, line_start + rand() % LINE_LEN);

			line_start += LINE_LEN;
	}
#endif

	for (int i=0; i < 10; i++) {
		int curr_pos = line_start + rand() % LINE_LEN;
		for (int j=0; j < LINE_LEN; j++) {
			if (j == curr_pos) {
				printf("%2c", 'X');
			} else {
				printf("%2c", EMPTY_SPOT);
			}
		}
		printf("\n");
	}

	return 0;
}
