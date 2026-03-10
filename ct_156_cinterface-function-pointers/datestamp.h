#ifndef _DATESTAMP_H
#define _DATESTAMP_H
#include <time.h>

#define DTSTMP_LEN 11

char dts[DTSTMP_LEN];

/* Usage:
 * char *datestmp_string = get_datestamp();
 * or
 * printf("Datestamp %s\n", get_datestamp());
 */
char *get_datestamp() {
	time_t t = time(NULL);
	struct tm *today = localtime(&t);
	sprintf(dts, "%d%02d%02d", today->tm_year + 1900, today->tm_mon + 1, today->tm_mday);
	return dts;
}
#endif

