#include <stdio.h>
#include <string.h>
#include <unistd.h>  // for sleep
#include "get_time_stamp.h"


int main(int argc, char **argv) {

	char *time3;

	printf("First tmstmp:  %s\n", get_time_stamp());

	sleep(2);
	printf("After 2 scnds: %s\n", get_time_stamp());

	sleep(3);
	time3 = get_time_stamp();
	printf("Time 3 (+3s):  %s\n", time3);

	return 0;
}

