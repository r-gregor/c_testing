/*
 * leap-years-display_v7.c
 * 20240321_06_en
 * 20240328_07_en: moved all time and localtime related parts into display_leap_years() function
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define YEARS_PER_LINE 22
#define GREGORIAN_CAL_INTRO 1582 // v6

#define INVERSE "\33[7m"
#define RESET "\33[m"

bool is_leap_year(int);
void display_leap_years(int, int);
void print_columns(int *, int);      // v5: 'int *' is same as 'int []'
void show_intro();


/* main */
int main(int argc, char **argv) {

	show_intro();
	display_leap_years(1, 2600);

	return 0;
} // end main

/* returns true if year is leap year */
bool is_leap_year(int year) {
	if (year < GREGORIAN_CAL_INTRO) return false; // v6
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}

/* iterates over years from to and insert leap years
 * into array, then formated display contents
 * of an array
 */
void display_leap_years(int starty, int endy) {

	// v7
	time_t now;
	struct tm *now_ptr;
	now = time(NULL);
	now_ptr = localtime(&now);

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

	int thisyear = now_ptr->tm_year + 1900;
	printf("Current year: %d -- is", thisyear);
	printf("%s leap year\n", is_leap_year(thisyear)? "" : " NOT");

	printf("---\n");

	printf("Leap years from %d to %d:\n", starty, endy);
	print_columns(leapyears, lcount);

	printf("---\n");

	printf("Special years (divisible by 4 but NOT leap years):\n");
	print_columns(specialyears, scount);

	printf("---\n");

}

/* formated printout of contents of an array
 * used in function display_leap_years()
 */
void print_columns(int *array, int count) {  // v5: int '*array' is same as 'int []'
	int clmns = 1;
	int lyear;
	char output[14];
	for (int i=0; i < count - 1; i++) {
		lyear = *(array + i);
		if (lyear % 400 == 0) {
			sprintf(output, " %s%d", INVERSE, lyear);
		} else {
			sprintf(output, " %d", lyear);
		}
		// if (clmns % YEARS_PER_LINE == 0) printf("%5d\n", lyear);      // v5: '*(array + i)' is same as 'array[i]'
		if (clmns % YEARS_PER_LINE == 0) printf("%s\n", output);      // v5: '*(array + i)' is same as 'array[i]'
		else printf("%s", output);                                  // v5: 'array[i]' is same as '*(array + i)'
		printf(RESET);
		clmns++;
	}
	printf("%5d\n", *(array + count - 1));   // v5: '*(array + count - 1)' is same as 'array[count - 1]'
}


void show_intro() {

	char *intro1 = "Every fourth year (years which, divided by 4, leave no remainder) is a\n"
	"leap year except those evenly divisible by 100 unless they're also evenly\n"
	"divisible by 400. This rule has been in effect since 1582 when the Gregorian\n"
	"calendar was first introduced.\n"
	"\n";

	char *intro2 = "    February 2000          February 2100          February 2400\n"
	"Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa\n"
	"       1  2  3  4  5       1  2  3  4  5  6          1  2  3  4  5\n"
	" 6  7  8  9 10 11 12    7  8  9 10 11 12 13    6  7  8  9 10 11 12\n"
	"13 14 15 16 17 18 19   14 15 16 17 18 19 20   13 14 15 16 17 18 19\n"
	"20 21 22 23 24 25 26   21 22 23 24 25 26 27   20 21 22 23 24 25 26\n"
	"27 28 29               28                     27 28 29\n"
	"---\n";
	
	printf("%s", intro1);

	char *c2 = intro2;
	while (*c2 != '\0') {
		if (*c2 == '2' && *(c2 + 1) == '9') {
			printf(INVERSE);
			printf("%c", *c2);
			printf("%c", *(c2 + 1));
			 printf(RESET);
			c2 += 2;
		} else {
			printf("%c", *c2);
			c2++;
		}
	}
	printf("\n");
}

