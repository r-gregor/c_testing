#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printOffset(time_t, int);

int main(int argc, char **argv) {

	time_t now = time(NULL);
	int offsets[] = {1, 7, 32, 90, 365, 3650};
	int ne = sizeof(offsets) / sizeof(offsets[0]);

	for (int i = 0; i < ne; i++) {
		printOffset(now, offsets[i]);
	}

	return 0;
}

void printOffset(time_t now, int offset) {
	char *today_str = ctime(&now);
	struct tm *cur_time = localtime(&now);
	cur_time->tm_mday += offset;
	time_t newTime = mktime(cur_time);
	printf("Current date is:        %s", today_str);
	printf("New date (+%d days) is: %s---\n", offset, ctime(&newTime));
}


