#ifndef _GETCURRYEAR_H
#define _GETCURRYEAR_H

#include <time.h>

time_t today;
struct tm *today_ptr;

/* declarations */
int get_curr_yr(void);


/* implementation */
/* returns current year as int */
int get_curr_yr(void) {

	today = time(NULL);
	today_ptr = localtime(&today);
	return today_ptr->tm_year + 1900;

}
#endif

