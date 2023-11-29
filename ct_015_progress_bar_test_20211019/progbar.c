#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>


const int PROG_BAR_LENGTH = 30;

/* update_bar function */
void update_bar(int percent_done) {
	int num_chars = percent_done * PROG_BAR_LENGTH / 100;
	printf("\r[");
	for (int i=0; i < num_chars; i++) {
		printf("#");
	}
	
	for (int i=0; i < (PROG_BAR_LENGTH - num_chars); i++) {
		printf(" ");
	}

	printf("] %d%% Done", percent_done);
	fflush(stdout);
}


/** main */
int main() {
	for (int i=0; i<=100; i++) {
		update_bar(i);
		usleep(2 * 1e4);
	}
	printf("\n");

	return 0;
}
