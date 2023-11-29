/*
 * Truncate A Dynamically Allocated String | C Programming Example
 * from:	https://www.youtube.com/watch?v=MiqLsSFrQP0
 *			(https://www.youtube.com/c/PortfolioCourses)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMCHARS 40
#define NINETH_CHAR 8

/*
 * V2
 */

char *dynamic_string_truncate(char *string, int idx);
void printAllChars(char *, int);

int main(int argc, char **argv) {

	char *string3 = malloc(NUMCHARS);
	strcpy(string3, "It works on my machine");

	printf("\n");
	printf("                              012345678\n");
	printf("                              123456789\n");
	printf("            Original string: ");
	printAllChars(string3, NUMCHARS);
	printf("; String length: %ld\n", strlen(string3));
	
	// truncating on 9-th character
	string3 = dynamic_string_truncate(string3, NINETH_CHAR);
	printf("           After truncating: \"");
	printf("%s\"", string3);
	printf("              ; String length: %ld\n", strlen(string3));
	printf("With printAllChars function: ");
	printAllChars(string3, NUMCHARS);
	printf(" ; String length: %ld\n", strlen(string3));

	printf("---\n"
			"Function printAllChars still prints all chars including those past\n"
			"truncating char because string is a pointer to the location\n"
			"in memory and index is just an offset from that point.\n"
			"The trucating char is, however, left out of the string as it\n"
			"was changed to '\\0' character.\n"
			"Which means that memory after the truncating point, although displayed,\n"
			"is available to the system.\n"
			"(It is only possible because realloc didn't move the pointer to some other location in memory)\n");

	printf("\n");

	free(string3);

	return 0;
}

/*
 * dynamically truncating a string function
 * truncating on char at index idx
 */
char *dynamic_string_truncate(char *string, int idx) {
	if (idx >= strlen(string)) {
		printf("Index out of range!\n");
		return NULL;
	}

	string[idx] = '\0';
	return realloc(string, idx + 1);
}

/**
 * print all characters of a string
 * shows all chars up to the memory size
 * if all chars were set to "." with memset,
 * or else just the chars in a string
 * parameters: string and LEN (defined)
 */
void printAllChars(char *str, int LEN) {
	printf("\"");
	for (int i=0; i < LEN; i++) {
		printf("%c", str[i]);
	}
	printf("\"");
}

