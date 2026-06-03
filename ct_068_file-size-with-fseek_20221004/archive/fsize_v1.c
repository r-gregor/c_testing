#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * V1
 * set size of string with length determined
 * by fseek() function on file.
 * read file into a string, print string.
 */

char *read_file(char *filename);
int length;

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

	printf("File size: %d bytes\n", length);
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

	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);

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

