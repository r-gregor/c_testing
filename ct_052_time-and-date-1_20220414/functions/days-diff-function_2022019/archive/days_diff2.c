#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** main */
int main(int argc, char **argv) {

	struct tm *start_d_ptr;
	struct tm *end_d_ptr;
	time_t start_d_scnds;
	char start_d[11];
	char end_d[11];
	double tdiff;

	time_t today_d_scnds = time(NULL);
	end_d_ptr = localtime(&today_d_scnds);
	start_d_ptr = localtime(&today_d_scnds);
	end_d_ptr->tm_isdst = -1;

	/**
	 * NOT WORKING ON CYGWIN??
	 * strptime("11.04.2021 00:00:00", "%d.%m.%Y %H:%M:%S", start_d_ptr);
	 */
	start_d_ptr->tm_year = 2022 - 1900;
	start_d_ptr->tm_mon = 4 - 1;
	start_d_ptr->tm_mday = 11;
	start_d_ptr->tm_isdst = -1;

	start_d_scnds = mktime(start_d_ptr);
	// test
	printf("start date: %s", ctime(&start_d_scnds));
	printf("end date: %s\n", ctime(&today_d_scnds));

	strftime(start_d, 11, "%d.%m.%Y", start_d_ptr);
	strftime(end_d, 11, "%d.%m.%Y", end_d_ptr);

	tdiff = difftime(today_d_scnds, start_d_scnds);
	printf("The difference between %s and %s is: %.0lf seconds ...\n", start_d, end_d, tdiff);
	printf("... which is %.0lf days.\n", tdiff/(3600*24));


	return 0;
} /* end main */

