#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

	// epoch time: seconds till 01.01.1970 00:00:
	time_t now = time(NULL);
	printf("Epoch time: %ld\n", now);

	// String representation of now
	// adds its own newline!
	char *today_str = ctime(&now);
	printf("time string:  %s",today_str);

	// ------------------------------------------------------------------------------------------------------
	// struct tm with parts of the date/time info:
	// gmtime: Greenwitch Mean Time
	printf("---\nGMT:\n");
	struct tm *gm_time = gmtime(&now);
	int linelen1 = -23;
	printf("%*s %12s %d\n", linelen1, "Seconds", "tm_sec: ", gm_time->tm_sec);
	printf("%*s %12s %d\n", linelen1, "Minutes", "tm_min: ", gm_time->tm_min);
	printf("%*s %12s %d\n", linelen1, "Hours", "tm_hour: ", gm_time->tm_hour);
	printf("%*s %12s %d\n", linelen1, "Month", "tm_mon: ", gm_time->tm_mon);
	printf("%*s %12s %d + 1900 = %d\n", linelen1, "Year", "tm_year: ", gm_time->tm_year, gm_time->tm_year + 1900);
	printf("%*s %12s %d\n", linelen1, "Day of the month", "tm_mday: ", gm_time->tm_mday);
	printf("%*s %12s %d\n", linelen1, "Day of the week", "tm_wday: ", gm_time->tm_wday);
	printf("%*s %12s %d\n", linelen1, "Day of the year", "tm_yday: ", gm_time->tm_yday);
	printf("%*s %12s %d\n", linelen1, "Is Daylight saving ON", "tm_isdst: ", gm_time->tm_isdst);

	// ------------------------------------------------------------------------------------------------------
	// localtime: Local time -> CET
	printf("---\nCET (local):\n");
	struct tm *cur_time = localtime(&now);
	int linelen2 = -23;
	printf("%*s %12s %d\n", linelen2, "Seconds", "tm_sec: ", cur_time->tm_sec);
	printf("%*s %12s %d\n", linelen2, "Minutes", "tm_min: ", cur_time->tm_min);
	printf("%*s %12s %d\n", linelen2, "Hours", "tm_hour: ", cur_time->tm_hour);
	printf("%*s %12s %d\n", linelen2, "Month", "tm_mon: ", cur_time->tm_mon);
	printf("%*s %12s %d + 1900 = %d\n", linelen2, "Year", "tm_year: ", cur_time->tm_year, cur_time->tm_year + 1900);
	printf("%*s %12s %d\n", linelen2, "Day of the month", "tm_mday: ", cur_time->tm_mday);
	printf("%*s %12s %d\n", linelen2, "Day of the week", "tm_wday: ", cur_time->tm_wday);
	printf("%*s %12s %d\n", linelen2, "Day of the year", "tm_yday: ", cur_time->tm_yday);
	printf("%*s %12s %d\n", linelen2, "Is Daylight saving ON", "tm_isdst: ", cur_time->tm_isdst);

	// ------------------------------------------------------------------------------------------------------
	// increase num of days
	printf("---\n");
	cur_time->tm_mday += 32;

	// create new time_t time
	time_t newTime = mktime(cur_time);
	int linelen3 = (23 + 12 + 2);
	printf("%*s%s", linelen3, "Current date is:  ", today_str);
	printf("%*s%s\n", linelen3, "New date (after 32 days) is:  ", ctime(&newTime));

	// ------------------------------------------------------------------------------------------------------
	// strftume function
	printf("---\n");

	// buffers to store strftime formatted strings in
	char s_date[9];
	char l_date[11];

	/* strftime takes struct tm as source !!
	 * ...
	 * struct tm *cur_time = localtime(&now);
	 * cur_time->tm_mday += 32;
	 * ...
	 */
	strftime(s_date, 9, "%Y%m%d", cur_time);
	strftime(l_date, 11, "%Y-%m-%d", cur_time);

	printf("Short date number: %s\n", s_date);
	printf("Long date number: %s\n", l_date);


	return 0;
}

