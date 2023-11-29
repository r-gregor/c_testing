/*
 * Truncate A Dynamically Allocated String | C Programming Example
 * from:	https://www.youtube.com/watch?v=MiqLsSFrQP0
 *			(https://www.youtube.com/c/PortfolioCourses)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMCHARS 25
#define NINETH_CHAR 8

/*
 * V1
 */

int main(int argc, char **argv) {

	printf("\nA - String stored in STACK memory:\n");
	//          123456789
	char string[NUMCHARS] = "It works on my machine";
	printf("                   012345678\n");
	printf("                   123456789\n");
	printf(" Original string: \"%s\"\n", string);

	
	// truncating on 9-th character
	string[NINETH_CHAR] = '\0';
	printf("After truncating: \"%s\"\n", string);

	printf("                                       0    ...   12\n");
	printf("Remaining characters in stack memory: ");
	printf("\"");
	for (int i = 9; i < NUMCHARS; i++) {
		printf("%c", string[i]);
	}
	printf("\"\n");

	printf("---\n");
	printf("B - String stored in HEAP memory:\n");
	
	// dealing with string lengths stored on heap!
	char *string2 = malloc(NUMCHARS);
	strcpy(string2, "It works on my machine");

	printf("                   012345678\n");
	printf("                   123456789\n");
	printf(" Original string: \"%s\"\n", string2);
	//
	// truncating on 9-th character
	string2[NINETH_CHAR] = '\0';
	string2 = realloc(string2, strlen(string2) + 1);

	printf("After truncating: \"%s\"\n", string2);


	free(string2);


	return 0;
}

