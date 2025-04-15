/*
 * obletnica-c.c
 * v1: 20250115 d
 * v2: 20250115 en
 * v3: 20250325 en
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREGORIAN_CAL_INTRO 1582

time_t today;
struct tm *today_ptr;

bool is_leap_year(int);

/* main */
int main(int argc, char **argv) {

	today = time(NULL);
	today_ptr = localtime(&today);
	int curry = today_ptr->tm_year + 1900;

	const int starty = 1989;
	int endy;
	long int years = 0;
	long int leaps = 0;
	long int days = 0;
	long int hours = 0;
	long int minutes = 0;
	long int seconds = 0;

	if (argc == 2) {
		endy = atoi(argv[1]);
	} else {
		endy = curry;
	}

	if (endy <= starty) {
		printf("Years difference to small. Chose another year\n");
		return -1;
	}

	for (int y = starty; y < endy; y++) {
		years++;
	
		if (is_leap_year(y))  {
			days += 366;
			leaps += 1;
		} else {
			days += 365;
		}
	}
	hours   += days * 24;
	minutes += hours * 60;
	seconds += minutes * 60;

	printf("---------------------------------------------\n");
	printf("%20s start date\n", "15.01.1989");
	printf("%20d current year\n", endy);
	printf("---------------------------------------------\n");
	printf("%20ld years (%ld leap years)\n", years, leaps);
	printf("%20ld days\n", days);
	printf("%20ld hours\n", hours);
	printf("%20ld minutes\n", minutes);
	printf("%20ld seconds\n", seconds);
	printf("---------------------------------------------\n");
	// printf("\n");


	return 0;
} /* end main */


/* returns true if year is leap year */
bool is_leap_year(int year) {
	if (year < GREGORIAN_CAL_INTRO) return false; // v6
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}

