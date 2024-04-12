#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	char line[] = "Gregor Redelonghi,22.02.1968";

	char *name = strtok(line, ",");
	int day   = atoi(strtok(NULL, "."));
	int month = atoi(strtok(NULL, "."));
	int year  = atoi(strtok(NULL, "."));

	printf("name: %s\n", name);
	printf("year: %d\n", year);
	printf("month: %d\n", month);
	printf("day: %d\n", day);

	printf("The sum of year+month+day is: %d\n", year+month+day);


	return 0;
}
