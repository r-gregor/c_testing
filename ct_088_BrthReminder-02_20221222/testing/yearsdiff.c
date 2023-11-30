#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
	
	int myyear = 1968;
	time_t today = time(NULL);
	struct tm *todayp = localtime(&today);

	printf("Current year: %d\n", todayp->tm_year + 1900);
	printf("Difference is: %d years\n", (todayp->tm_year + 1900) - myyear);

	return 0;
}

