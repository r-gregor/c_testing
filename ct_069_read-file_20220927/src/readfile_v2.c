#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

#define FILENAME_SIZE 1024

/*
 * V2
 */


int main(int argc, char **argv) {

	FILE *file;
	char filename[FILENAME_SIZE];

	// v2
	if (argc == 2) {
		strcpy(filename, argv[1]);
	} else {
		printf("Filename: ");
		fgets(filename, FILENAME_SIZE, stdin);
		filename[strlen(filename) - 1] = '\0';
	}

	file = fopen(filename, "r");

	if (file == NULL) {
		printf("Error opening file(s)!\n");
		return 1;
	}

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

