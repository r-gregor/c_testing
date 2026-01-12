// Code

#include <stdio.h>
#include <stdbool.h>

#define DAYS_OF_FEB_LEAP 29U
#define NO_OF_MONTHS 12U

const char gMonthsNames[][NO_OF_MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
const int gDays[NO_OF_MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};

int getNumberOfDays(int mm, int yy) {
	int days = 0;

	if ((mm > 0) && (mm <= 12 ) && (yy > 0) && (yy <= 9999)) {
		if (mm == 2) {

			// Leap year calculate
			bool leap = ((yy % 4) == 0);
			days = leap ? DAYS_OF_FEB_LEAP : gDays[mm - 1];
		} else {
			days = gDays[mm - 1];
		}
	}
	return days;
}

int main() {
	int mm;
	int yy;

	while (1) {
		printf("Please enter the month of the year in MM-YYYY format (or 0/00 to quit): ");
		scanf("%d-%d",&mm,&yy);
		
		// my addition
		if (mm == 0) {
			printf("Bye!\n");
			return 0;
		}

		int numOfDays = getNumberOfDays(mm, yy);

		if ( numOfDays != 0) {
			printf("There are %d days in %s on %d.\n", numOfDays, gMonthsNames[mm - 1], yy);
		} else {
			printf("Invalid date or month, please input the values in MM-YYYY format\n");
		}
	}
	return 0;
}

