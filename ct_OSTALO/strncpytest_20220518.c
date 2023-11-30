#include <stdio.h>
#include <string.h>

#define NUM_CHARS 14

int main(int argc, char **argv) {

	char *line = "What's.up.0.my.Capitan?";
	printf("Unchanged line: %s\n", line);

	char line2[strlen(line) + 1];                     // set length of original line
	strcpy(line2, line);
	printf("Changed line2: %s\n", line2);

	char line3[(NUM_CHARS * sizeof(char)) + 1];       // set lenght of line 3
	strncpy(line3, line, NUM_CHARS * sizeof(char));   // copies chars without terminating null char
	printf("line3 length: \"%ld\"\n", strlen(line3));
	line3[strlen(line3)] = '\0';                      // add '\0' (null) char at the end of string
	printf("Changed line3: \"%s\"\n", line3);
	printf("\"");                                     // initial '"'
	for (int j=0; j < strlen(line3) - 1; j++) {       // all (chars) with 3 trailing spaces, except last char
		printf("%c   ", line3[j]);
	}
	printf("%c\"", line3[strlen(line3) - 1]);         // last char without trailing spaces and with ending '"'
	printf("\n");

	printf("\"");                                     // initial '"'
	for (int i = 1; i < NUM_CHARS; i++) {             // all digits with trailing spaces, but last one
		if (i < 10) {                                 // if single digit num -> with 3 trailing spaces
			printf("%d   ", i);
		} else {
			printf("%d  ", i);                        // else with 2 trailing spaces
		}
	}
	printf("%d\"", NUM_CHARS);                        // last digit without trailing spaces and with ending '"'
	printf("\n");

	return 0;
}

