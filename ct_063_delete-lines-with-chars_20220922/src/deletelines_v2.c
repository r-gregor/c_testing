#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/*
 * V2
 * program to delet all lines from a file that have
 * at least one character from the certain group of letters
 */


int main() {

	char filename[FILENAME_SIZE];
	char temp_filename[FILENAME_SIZE];
	char delete_chars[MAX_LINE];
	char buffer[MAX_LINE];

	FILE *file, *temp, *rfile;
	printf("Filename: ");
	fgets(filename, FILENAME_SIZE, stdin);

	// removing terminating '\n'
	filename[strlen(filename) - 1] = '\0';

	// temp____file.txt
	strcpy(temp_filename, "temp____");
	strcat(temp_filename, filename);

	printf("Delete chars: ");
	fgets(delete_chars, MAX_LINE, stdin);
	// removing terminating '\n'
	delete_chars[strlen(delete_chars) - 1] = '\0';

	file = fopen(filename, "r");
	temp = fopen(temp_filename, "w");

	if (file == NULL || temp == NULL) {
		printf("Error opening file(s)!\n");
		return 1;
	}

	bool keep_reading = true;

	do {
		fgets(buffer, MAX_LINE, file);

		if (ferror(file)) {
			printf("Error reading file!\n");
			fclose(temp);
			remove(temp_filename);
			return 1;
		}
		else if (feof(file)) keep_reading = false;
		else if (strpbrk(buffer, delete_chars) == NULL) {
			fputs(buffer, temp);
		}

	} while (keep_reading);

	fclose(file);
	fclose(temp);

	remove(filename);
	rename(temp_filename, filename);
	
	rfile = fopen(filename, "r");
	char rbuffer[FILENAME_SIZE];

	/*
	if ((fread(&rbuffer, 1, FILENAME_SIZE, rfile)) != FILENAME_SIZE - 1) {
		fprintf(stderr, "Reading file failed!\n");
		return 1;
	}
	*/

	int charsnum = fread(&rbuffer, 1, FILENAME_SIZE, rfile);

	printf("---\nContents of %s:\n", filename);
	for (int i=0; i < charsnum; i++) {
		printf("%c", rbuffer[i]);
	}
	
	fclose(rfile);

	return 0;
}

