/*
 * countdown_timer_v2.c
 * from: Countdown Timer | C Programming Example (Portfolio Courses)
 *       https://www.youtube.com/watch?v=dG1HBSArgjM
 * 20230911 (en)
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {

	int seconds = 0;

	printf("Enter number of seconds to countdown: ");
	scanf("%d", &seconds);

	while(seconds > 0) {
		// v2
		printf("\r%04d", seconds);
		fflush(stdout); // because no '\n' in previous statemnet

		clock_t stop = clock() + CLOCKS_PER_SEC;
		while(clock() < stop) {};

		seconds--;
	}

	// v2
	printf("\rTime's up!\n");

	return 0;
}

