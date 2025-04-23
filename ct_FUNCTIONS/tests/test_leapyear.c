#include <stdio.h>
#include <string.h>
#include "isleapyear.h"


int main(void) {
	int starty = 2000;
	int endy = 2025;
	printf("Leap years between %d and %d:\n", starty, endy);
	for (int year = starty; year < endy; year++) {
		if (is_leap_year(year)) {
			printf("%d\n", year);
		}
	}

	return 0;
}
