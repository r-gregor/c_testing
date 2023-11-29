#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * v2
 */

bool is_leap_year(int);
void display_leap_years(int, int);
void display_special_years(int, int);

int main(int argc, char **argv) {

	display_leap_years(1600, 2205);
	printf("---\n");
	display_special_years(1600, 2205);


	return 0;
}

bool is_leap_year(int year) {
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}


void display_leap_years(int starty, int endy) {
	int size = (endy - starty);
	int leapyears[size];
	int curryear = starty;
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (is_leap_year(curryear)) {
			leapyears[count] = curryear;
			count++;
		}
		curryear++;
	}
	
	printf("Leap years from %d to %d:\n", starty, endy);
	int clmns = 1;
	for (int j=0; j < count - 1; j++) {
		if (clmns % 12 == 0) printf("%d\n", leapyears[j]);
		else printf("%d, ", leapyears[j]);
		clmns++;
	}
	printf("%d\n", leapyears[count - 1]);
}

void display_special_years(int starty, int endy) {
	printf("Special years (divisible by 4 but NOT leap years):\n");
	int cnt = 0;
	for (int year = starty; year < endy; year++) {
		if (year % 4 == 0 && !is_leap_year(year)) {
			cnt++;
			if (cnt % 12 == 0) printf("%d\n", year);
			else printf("%d, ", year);
		}
	}
	printf("\n");
}
