#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H
#include <time.h>

#define TMPSTMP_LEN 16

char tms[TMPSTMP_LEN];

/* Usage:
 * char *timestmp_string = get_timestamp();
 * or
 * printf("Timestamp: %s\n", get_timestamp());
 */
char *get_timestamp() {
	time_t t = time(NULL);
	struct tm *now_ptr = localtime(&t);
	sprintf(tms, "%d%02d%02d_%02d%02d%02d",
							now_ptr->tm_year + 1900,
							now_ptr->tm_mon + 1,
							now_ptr->tm_mday,
							now_ptr->tm_hour,
							now_ptr->tm_min,
							now_ptr->tm_sec);
	return tms;
}
#endif

