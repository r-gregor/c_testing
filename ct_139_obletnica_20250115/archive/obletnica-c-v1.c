/*
 * obletnica_36_v1.c
 * v1: 20250115 d
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

time_t today;
struct tm *today_ptr;


int main(int argc, char **argv) {

	today = time(NULL);
	today_ptr = localtime(&today);
	int curry = today_ptr->tm_year + 1900;

	int endy;
	long int years = 0;
	long int days = 0;
	long int hours = 0;
	long int minutes = 0;
	long int seconds = 0;

	if (argc == 2) {
		endy = atoi(argv[1]);
	} else {
		endy = curry;
	}

	for (int y = 1989; y < endy; y++) {
		years++;
		if (y % 4 == 0) {
			days += 366;
		} else {
			days += 365;
		}
		hours       += days * 24;
		minutes     += hours * 60;
		seconds += minutes * 60;
	}

	printf("---------------------------------\n");
	printf("%20d current year\n", endy);
	printf("---------------------------------\n");
	printf("%20ld years\n", years);
	printf("%20ld days\n", days);
	printf("%20ld hours\n", hours);
	printf("%20ld minutes\n", minutes);
	printf("%20ld seconds\n", seconds);
	printf("---------------------------------\n");
	printf("\n");


	return 0;
}
