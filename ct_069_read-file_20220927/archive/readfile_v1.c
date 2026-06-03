#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

#define FILENAME_SIZE 1024

/*
 * V1
 */


int main() {

	char filename[FILENAME_SIZE];

	FILE *file;
	printf("Filename: ");
	fgets(filename, FILENAME_SIZE, stdin);

	// removing terminating '\n'
	filename[strlen(filename) - 1] = '\0';

	file = fopen(filename, "r");

	if (file == NULL || temp == NULL) {
		printf("Error opening file(s)!\n");
		return 1;
	}

	printf("---\nContents of %s:\n", filename);
	char c;
	while (true) {
		c = fgetc(file);

		if (feof(file)) break;
		if (ferror(file)) break;

		printf("%c", c);
	}
	// ---------------------------------------------
	
	fclose(file);

	return 0;
}

