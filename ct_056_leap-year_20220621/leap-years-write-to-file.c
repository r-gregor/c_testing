#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define YEARS_PER_LINE 22

/**
 * v2
 * write to file: leap-years_YYYYmmdd_HHMMSS.txt
 */


bool is_leap_year(int);
void write_leap_years(int, int);
void write_columns(int *, int);
FILE *fd;
char *fname;

time_t now;
struct tm *now_ptr;

/* main */
int main(int argc, char **argv) {

	now = time(NULL);
	now_ptr = localtime(&now);

	char fname[31];
	sprintf(fname, "leap-years_%d%02d%02d_%02d%02d%02d.txt",
							now_ptr->tm_year + 1900,
							now_ptr->tm_mon + 1,
							now_ptr->tm_mday,
							now_ptr->tm_hour,
							now_ptr->tm_min,
							now_ptr->tm_sec);

	fd = fopen(fname, "w");

	if (fd == NULL) {
		fprintf(stderr, "File could'nt be open for writing!");
		exit(EXIT_FAILURE);
	}

	write_leap_years(1, 2205);

	return 0;
} // end main

/* returns true if year is leap year */
bool is_leap_year(int year) {
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}

/* iterates over years from to and insert leap years
 * into array, then formated write contents
 * of an array into an external file
 */
void write_leap_years(int starty, int endy) {
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

	fprintf(fd, "Leap years from %d to %d:\n", starty, endy);
	write_columns(leapyears, lcount);

	fprintf(fd, "---\n");

	fprintf(fd, "Special years (divisible by 4 but NOT leap years):\n");
	write_columns(specialyears, scount);

	fprintf(fd, "---\n");

	fclose(fd);
}

/* write formated lines of contents of an array
 * used in function display_leap_years() into
 * external file
 */
void write_columns(int *array, int count) {
	int clmns = 1;
	for (int i=0; i < count - 1; i++) {
		if (clmns % YEARS_PER_LINE == 0) {
			fprintf(fd, "%5d\n", *(array + i));
		} else {
			fprintf(fd, "%5d, ", array[i]);
		}
		clmns++;
	}
	fprintf(fd, "%5d\n", *(array + count - 1));
}

