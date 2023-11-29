/*
 * countdown_timer_v3.c
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
		// v3
		int hrs = seconds / 3600;
		int mnts = (seconds % 3600) / 60;
		int scnds = seconds % 60;

		// v3
		printf("\r%02d:%02d:%02d", hrs, mnts, scnds);
		fflush(stdout); // because no '\n' in previous statement

		clock_t stop = clock() + CLOCKS_PER_SEC;
		while(clock() < stop) {};

		seconds--;
	}

	// v2
	printf("\rTime's up!\n");

	return 0;
}

