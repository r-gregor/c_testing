#ifndef _GET_TIME_STAMP_H
#define _GET_TIME_STAMP_H

#include <stdio.h>
#include <string.h>
#include <time.h>

#define TMPSTMP_LEN 16

/**
 * returns timestamp as char pointer as: "YYYYmmdd_HHMMSS"
 * usage: - create a char pointer: char *time1
 *        - asign its value: time1 = get_time_stamp(), or
 *        - use it directly in printf function: printf("Time1 is: %s\n", get_time_stamp())
 */
char *get_time_stamp();

struct tm *now_ptr;
char tmpstmp[TMPSTMP_LEN];

char *get_time_stamp() {

	time_t now;
	time(&now);

	now_ptr = localtime(&now);
	sprintf(tmpstmp, "%d%02d%02d_%02d%02d%02d",
							now_ptr->tm_year + 1900,
							now_ptr->tm_mon + 1,
							now_ptr->tm_mday,
							now_ptr->tm_hour,
							now_ptr->tm_min,
							now_ptr->tm_sec);
	return tmpstmp;
}

#endif

