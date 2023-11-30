#include <stdio.h>
#include <string.h>


int isLeapYear(int);
int currYr;

int main(int argc, char **argv) {

	for (int n=0; n < 32; n++) {
		currYr = 2000 + n;

		if (isLeapYear(currYr)) {
			printf ("*** The year %d is LEAP year! ***\n", currYr);
		} else {
			printf ("The year %d is normal year.\n", currYr);
		}
	}


	return 0;
}

int isLeapYear(int currYr) {
	return ((currYr % 4 == 0) && (currYr % 100 != 0)) || (currYr % 400 == 0);

}
