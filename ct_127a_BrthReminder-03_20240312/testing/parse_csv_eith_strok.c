#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	char line[] = "Gregor Redelonghi,22.02.1968";

	char *name = strtok(line, ",");
	char *day = strtok(NULL, ".");
	char *month = strtok(NULL, ".");
	char *year = strtok(NULL, ".");

	printf("name: %s\n", name);
	printf("year: %s\n", year);
	printf("month: %s\n", month);
	printf("day: %s\n", day);


	return 0;
}
