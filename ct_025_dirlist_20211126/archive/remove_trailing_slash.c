#include <stdio.h>
#include <string.h>

void remove_endslash(char *);

int main() {
	
	char line1[] = "/home/gregor.redelonghi/majstaf/coding/";
	char line2[] = "/home/gregor.redelonghi/majstaf";

	printf("Line1: %s\n", line1);
	remove_endslash(line1);

	printf("Line2: %s\n", line2);
	remove_endslash(line2);

/*
 * 	char last1 = line1[strlen(line1) - 1];
 * 	printf("Last char of Line1: %c\n", last1);
 * 
 * 	if (last1 == '/') {
 * 		line1[strlen(line1) - 1] = '\0';
 * 	}
 */


	return 0;
}

void remove_endslash(char *line) {

	char last = line[strlen(line) - 1];
	printf("Last char of %s is: [ %c ]\n", line, last);

	if (last == '/') {
		line[strlen(line) - 1] = '\0';
	}

	printf("New : %s\n", line);

}
