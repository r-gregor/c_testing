#include <stdio.h>
#include <string.h>
#include <time.h>

/** main */
int main(int argc, char **argv) {

	struct tm year1, year2;
	time_t seconds1, seconds2;
	char date1[11];
	char date2[11];
	double tdiff;


	year1.tm_year = 2021 - 1900;
	year1.tm_mon = 2 - 1;
	year1.tm_mday = 22;
	year1.tm_hour = 0;
	year1.tm_min = 0;
	year1.tm_sec = 0;
	year1.tm_isdst = 0;

	year2.tm_year = 2022 - 1900;
	year2.tm_mon = 2 - 1;
	year2.tm_mday = 18;
	year2.tm_hour = 0;
	year2.tm_min = 0;
	year2.tm_sec = 0;
	year2.tm_isdst = 0;

	seconds1 = mktime(&year1);
	seconds2 = mktime(&year2);

	/*
	// test
	printf("seconds1: %ld\n", seconds1);
	printf("seconds2: %ld\n", seconds2);
	*/

	strftime(date1, 11, "%d.%m.%Y", &year1);
	strftime(date2, 11, "%d.%m.%Y", &year2);

	tdiff = difftime(seconds2, seconds1);
	printf("The difference between %s and %s is: %.0lf seconds ...\n", date1, date2, tdiff);
	printf("... which is %.0lf days.\n", tdiff/(3600*24));


	return 0;
} /* end main */

