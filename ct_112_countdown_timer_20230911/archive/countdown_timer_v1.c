/*
 * countdown_timer_v1.c
 * from: Countdown Timer | C Programming Example (Portfolio Courses)
 *       https://www.youtube.com/watch?v=dG1HBSArgjM
 * 20230911 (en)
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {

	int seconds = 0;

	printf("Enter number of seconds to countdown: \n");
	scanf("%d", &seconds);

	while(seconds > 0) {
		printf("%d\n", seconds);

		clock_t stop = clock() + CLOCKS_PER_SEC;
		while(clock() < stop) {};

		seconds--;
	}

	printf("Tiime's up!\n");

	return 0;
}

