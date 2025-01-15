#ifndef _GETCURRYEAR_H
#define _GETCURRYEAR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

time_t today;
struct tm *today_ptr;

int get_curr_yr(void);

int get_curr_yr(void) {

	today = time(NULL);
	today_ptr = localtime(&today);
	return today_ptr->tm_year + 1900;

}
#endif

