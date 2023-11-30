#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
 * V3
 * set size of string with length determined
 * by stat function on file -- better
 * as there is no need to open a file.
 * read file into a string, print string.
 */

char filename[1024];
long get_file_size(char *filename);
long length;

int main(int argc, char **argv) {

	if (argc == 2) {
		strcpy(filename, argv[1]);
	} else {
		printf("File: ");
		scanf("%s", filename);
	}
	

	if ((length = get_file_size(filename)) == -1) {
		return 1;
	}

	printf("File name: %s\n", filename);
	printf("File size: %ld bytes\n", length);

	return 0;
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

