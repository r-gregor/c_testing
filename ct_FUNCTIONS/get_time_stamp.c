#include <stdio.h>
#include <string.h>
#include <time.h>

#define TMPSTMP_LEN 16

/**
 * timestamp: "YYYYmmdd_HHMMSS"
 */

time_t now;
struct tm *now_ptr;

/* main */
int main(int argc, char **argv) {

	now = time(NULL);
	now_ptr = localtime(&now);

	char timestmp[TMPSTMP_LEN];
	sprintf(timestmp, "%d%02d%02d_%02d%02d%02d",
							now_ptr->tm_year + 1900,
							now_ptr->tm_mon + 1,
							now_ptr->tm_mday,
							now_ptr->tm_hour,
							now_ptr->tm_min,
							now_ptr->tm_sec);

