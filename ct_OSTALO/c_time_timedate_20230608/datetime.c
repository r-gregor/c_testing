#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	time_t t = time(NULL);
	struct tm date = *localtime(&t);

	int year;
	int month;
	int day;

	printf("Input date (YYYY-MM-dd): ");
	scanf("%d-%d-%d", &year, &month, &day);

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = 0;
	date.tm_min = 0;

	char dateString[200];
	strftime(dateString, 200, "%Y %B %d %I:%M%p", &date);
	printf("Current date and time is %s\n", dateString);
	return 0;
}

