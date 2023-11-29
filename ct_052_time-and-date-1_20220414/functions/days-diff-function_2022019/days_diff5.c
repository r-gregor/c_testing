#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void printDateDiff(double);
double getDaysDiffInScnds(int, int, int);

struct tm *start_d_ptr;
struct tm *end_d_ptr;
time_t start_d_scnds;
char start_d[11];
char end_d[11];

/** main */
int main(int argc, char **argv) {
	printDateDiff(getDaysDiffInScnds(2022,1,7));
	printDateDiff(getDaysDiffInScnds(2022,4,7));
	printDateDiff(getDaysDiffInScnds(1968,2,22));
	printDateDiff(getDaysDiffInScnds(2022,2,22));
	printDateDiff(getDaysDiffInScnds(2023,1,1));

	return 0;
} /* end main */

/**
 * calculate and print difference in (years),days
 * of time difference in seconds
 */
void printDateDiff(double tdiff) {
	const double days_in_year = 365.2544;
	const double scnds_in_year= days_in_year*24*3600;

	if (tdiff >= scnds_in_year) {
		double yrs = tdiff / scnds_in_year;
		double dys = (yrs - floor(tdiff/scnds_in_year)) * days_in_year;
		printf("The difference between %s and %s is %.0lf seconds = ", start_d, end_d, tdiff);
		printf("%.0lf years and %.0lf days.\n", yrs, dys);
	} else {
		printf("The difference between %s and %s is %.0lf seconds = ", start_d, end_d, tdiff);
		printf("%.0lf days.\n", tdiff/(3600*24));
	}
} /* end printDateDiff */

/**
 * calculate difference in seconds between two dates
 * today and other date
 */
double getDaysDiffInScnds(int _year, int _month, int _day) {
	time_t today_d_scnds = time(NULL);

	/** start */
	// start_d_ptr is pointer, so it needs to be initialized ...
	start_d_ptr = localtime(&today_d_scnds);

	// ... and then changed explicitly
	start_d_ptr->tm_year = _year - 1900;
	start_d_ptr->tm_mon = _month - 1;
	start_d_ptr->tm_mday = _day;
	start_d_ptr->tm_isdst = -1;
	start_d_scnds = mktime(start_d_ptr);
	strftime(start_d, 11, "%d.%m.%Y", start_d_ptr);

	/** end */
	// end_d_ptr is pointing to same location as start_d_ptr, so it
	// needs to be re-initialized with localtime function
	end_d_ptr = localtime(&today_d_scnds);
	end_d_ptr->tm_isdst = -1;
	strftime(end_d, 11, "%d.%m.%Y", end_d_ptr);

	return difftime(today_d_scnds, start_d_scnds);
} /* end getDaysDiffInScnds */

