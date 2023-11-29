#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
 * V2
 * set size of string with length determined
 * by stat function on file -- better
 * as there is no need to open a file.
 * read file into a string, print string.
 */

char *read_file(char *filename);
long get_file_size(char *filename);
long length;

int main(int argc, char **argv) {
	
	char filename[1024];
	printf("File: ");
	scanf("%s", filename);

	// gets pointer to allocated area --> must be freed!
	char *file_contents = read_file(filename);

	if (file_contents == NULL) {
		printf("Error reading file!\n");
		return 1;
	}

	printf("File size: %ld bytes\n", length);
	printf("File contents:\n\n%s\n", file_contents);

	free(file_contents);


	return 0;
}

/*
 * function allocates memor on heap
 * and returns a pointer to it
 * so it must be freed
 */
char *read_file(char *filename) {

	FILE *file = NULL;
	file = fopen(filename, "r");

	if (file == NULL) return NULL;

	length = get_file_size(filename);


	// +1 for terminating '\0' character
	char *string = malloc(sizeof(char) * (length + 1));

	char c;
	int i = 0;

	while ((c = fgetc(file)) != EOF ) {
		string[i] = c;
		i++;
	}
	string[i] = '\0';

	return string;

}

/*
 * get file size without opening file
 * better (faster) using stat
 * must include "sys/stat.h" library
 */
long get_file_size(char *filename) {
	struct stat file_status;
	if (stat(filename, &file_status) < 0) {
		printf("Error getting file status!\n");
		return -1;
	}

	return file_status.st_size;
}

