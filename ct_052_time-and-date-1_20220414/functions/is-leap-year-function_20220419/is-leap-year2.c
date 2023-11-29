#include <stdio.h>
#include <string.h>

/** v2
 * get the year as user imput
 */

int isLeapYear(int);
int currYr;

/** main */
int main(int argc, char **argv) {

	printf("Enter a year: ");
	scanf("%d", &currYr);

	if (isLeapYear(currYr)) {
		printf ("*** The year %d is LEAP year! ***\n", currYr);
	} else {
		printf ("The year %d is normal year.\n", currYr);
	}

	return 0;
} /** end main */

/** is it leap year? */
int isLeapYear(int currYr) {
	return ((currYr % 4 == 0) && (currYr % 100 != 0)) || (currYr % 400 == 0);
}

