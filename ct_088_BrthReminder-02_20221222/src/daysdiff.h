#ifndef _DAYSDIFF_H
#define _DAYSDIFF_H
/*
 * from: https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/
 */
#include <stdio.h>
#include <string.h>

typedef struct Date {
	int d;
	int m;
	int y;
} Date;

// This function counts number of 
// leap years before the given date
int countLeapYears(Date *d);

// This function returns number of 
// days between two given dates
int getDifference(Date *dt1, Date *dt2);

#endif
