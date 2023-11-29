#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	// char input;
	while(1) {
		printf("Enter a character: ");
		char input;
		// space befor '%c' to prevent scanf to accept newline character into input buffer
		// to prevent the line 'Enter a character' to be printed twice ina a row!!
		scanf(" %c", &input);

		if (input != '\n') {
			if (input >= 48 && input <= 57) {
				printf("Character '%c' is a digit!\n", input);
			} else if (input >= 65 && input <= 90) {
				printf("Character '%c' is a UPPER-CASE letter!\n", input);
			} else if (input >= 97 && input <= 122) {
				printf("Character '%c' is a lower-case letter!\n", input);
			} else {
				printf("Character '%c' is NOT an ascii letter or digit!\n", input);
			}
		}
	}

	return 0;
}

