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
 * V3
 * testing phaze
 */

char *dynamic_string_truncate(char *string, int idx);
void printAllChars(char *, int);

int main(int argc, char **argv) {

	char *string3 = malloc(NUMCHARS);
	memset(string3, '.',NUMCHARS);
	strcpy(string3, "It works on my machine");

	printf("                   012345678\n");
	printf("                   123456789\n");
	printf(" Original string: ");
	printAllChars(string3, NUMCHARS);
	printf("String length: %ld\n", strlen(string3));
	
	// truncating on 9-th character
	string3 = dynamic_string_truncate(string3, NINETH_CHAR);
	printf("After truncating: \"");
	printf("%s\"\n", string3);
	printf("String length: %ld\n", strlen(string3));
	printf("---\n");
	printf("With printAllChars function:\n");
	printAllChars(string3, NUMCHARS);
	printf("String length: %ld\n", strlen(string3));


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
	printf("\"\n");
}

