/*
 * v1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINE_LEN 32

int main(int argc, char **argv) {

	srand(time(0));
	int line_start = 0;
	int line_end = 0;
	for (int i=0; i < 10; i++) {
			line_end = line_start + LINE_LEN - 1;
			printf("line start: %d, line end: %d, current offset: %d\n", line_start, line_end, line_start + rand() % LINE_LEN);

			line_start += LINE_LEN;
	}


	return 0;
}
