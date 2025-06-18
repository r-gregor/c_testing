/*
 * filename: lookup-table-test.c
 * 20250618 v1 en
 * 20250618 v2 d
 */

#include <stdio.h>
#include <string.h>

const char *week_days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Sunday"
};

void print_weekday(int num);

int main(int argc, char **argv) {

	print_weekday(1);
	print_weekday(11);
	print_weekday(14);
	print_weekday(0);
	print_weekday(-1);
	print_weekday(24);
	print_weekday(7);
	print_weekday(9);
	print_weekday(4);
	print_weekday(3);
	print_weekday(2);

	return 0;
}

void print_weekday(int num) {
	if (num <= 0) { // v2
		// printf("Day of the week at number %5d: ", num);
		// printf("-- must be 0 or greater\n");
		return;
	}

	unsigned int day = num % 7;
	printf("Day of the week at number %5d: is %s\n", num, week_days[day]);
}

