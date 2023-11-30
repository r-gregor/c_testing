#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define YEARS_PER_LINE 22

/**
 * v4
 */

bool is_leap_year(int);
void display_leap_years(int, int);
void print_columns(int [], int);

int main(int argc, char **argv) {

	display_leap_years(1, 2205);

	return 0;
}

bool is_leap_year(int year) {
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}


void display_leap_years(int starty, int endy) {
	int yearsnum = endy - starty;
	int size = yearsnum / 4;
	int leapyears[size];
	int specialyears[size];
	int curryear = starty;
	int lcount = 0;
	int scount = 0;

	for (int i = 0; i < yearsnum; i++) {
		if (is_leap_year(curryear)) {
			leapyears[lcount] = curryear;
			lcount++;
		} else if (curryear % 4 == 0 && !is_leap_year(curryear)) {
			specialyears[scount] = curryear;
			scount++;
		}
		curryear++;
	}

	printf("Leap years from %d to %d:\n", starty, endy);
	print_columns(leapyears, lcount);

	printf("---\n");

	printf("Special years (divisible by 4 but NOT leap years):\n");
	print_columns(specialyears, scount);

	printf("---\n");

}

void print_columns(int array[], int count) {
	int clmns = 1;
	for (int i=0; i < count - 1; i++) {
		if (clmns % YEARS_PER_LINE == 0) printf("%5d\n", array[i]);
		else printf("%5d, ", array[i]);
		clmns++;
	}
	printf("%5d\n", array[count - 1]);
}

