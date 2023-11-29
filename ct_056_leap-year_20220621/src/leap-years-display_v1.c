#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * v1
 */

bool is_leap_year(int);

int main(int argc, char **argv) {

	for (int year = 1600; year < 2200; year++) {
		if (is_leap_year(year)) {
			printf("%d LEAP YEAR\n", year);
		} else {
			printf("%d\n", year);
		}
	}

	printf("Special years (divisible by 4 but NOT leap years):\n");
	int cnt = 0;
	for (int year = 1; year < 2200; year++) {
		if (year % 4 == 0 && !is_leap_year(year)) {
			cnt++;
			if (cnt % 11 == 0) printf("%d\n", year);
			else printf("%d, ", year);
		}
	}
	printf("\n");

	return 0;
}

bool is_leap_year(int year) {
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}

