#ifndef _ISLEAPYEAR_H
#define _ISLEAPYEAR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREGORIAN_CAL_INTRO 1582

bool is_leap_year(int);


/* implementation */
/* returns true if year is leap year */
bool is_leap_year(int year) {
	if (year < GREGORIAN_CAL_INTRO) return false; // v6
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}

#endif

