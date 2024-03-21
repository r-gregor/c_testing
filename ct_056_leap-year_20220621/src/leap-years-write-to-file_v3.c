/*
 * leap-years-write-to-file_v3.c
 * 20240321_03_en
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define YEARS_PER_LINE 22
#define GREGORIAN_CAL_INTRO 1582 // v3

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

	char fname[38];
	sprintf(fname, "OUTPUT_leap-years_%d%02d%02d_%02d%02d%02d.txt",
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

	write_leap_years(1, 2600);
	printf("Output written to: %s\n", fname);

	return 0;
} // end main

/* returns true if year is leap year */
bool is_leap_year(int year) {
	if (year < GREGORIAN_CAL_INTRO) return false; // v3
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

char *intro = "Every fourth year (years which, divided by 4, leave no remainder) is a\n"
"leap year except those evenly divisible by 100 unless they're also evenly\n"
"divisible by 400. This rule has been in effect since 1582 when the Gregorian\n"
"calendar was first introduced.\n"
"\n"
"    February 2000          February 2100          February 2400\n"
"Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa\n"
"       1  2  3  4  5       1  2  3  4  5  6          1  2  3  4  5\n"
" 6  7  8  9 10 11 12    7  8  9 10 11 12 13    6  7  8  9 10 11 12\n"
"13 14 15 16 17 18 19   14 15 16 17 18 19 20   13 14 15 16 17 18 19\n"
"20 21 22 23 24 25 26   21 22 23 24 25 26 27   20 21 22 23 24 25 26\n"
"27 28 29               28                     27 28 29\n"
"---\n";

	int yearsnum = endy + 1 - starty;
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
		} else if (curryear > GREGORIAN_CAL_INTRO && curryear % 4 == 0 && !is_leap_year(curryear)) {
			specialyears[scount] = curryear;
			scount++;
		}
		curryear++;
	}

	fprintf(fd, "%s", intro);

	int thisyear = now_ptr->tm_year + 1900;
	fprintf(fd, "Current year: %d -- is", thisyear);
	fprintf(fd, "%s leap year\n", is_leap_year(thisyear)? "" : " NOT");

	fprintf(fd, "---\n");

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

