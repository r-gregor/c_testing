#ifndef _DATESTAMP_H
#define _DATESTAMP_H
#include <time.h>

#define DTSTM_LEN 11

char dt[DTSTM_LEN];

/* Usage:
 * char *datestmp_string = make_datestamp();
 */
char *make_datestamp() {
	time_t t = time(NULL);
	struct tm *today = localtime(&t);
	sprintf(dt, "%d%02d%02d", today->tm_year + 1900, today->tm_mon + 1, today->tm_mday);
	return dt;
}
#endif

