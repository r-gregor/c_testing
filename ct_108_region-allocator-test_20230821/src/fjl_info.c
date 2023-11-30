#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	char fname[30];
	if (argc ==2) {
		strcpy(fname, argv[1]);
	} else {
		strcpy(fname, "big_100MB_file.txt");
	}

	FILE *fp = fopen(fname, "r");
	if (fp == NULL) {
		fprintf(stderr, "Could not open the file\n");
		return 1;
	}

	fseek(fp, 0, SEEK_END);
	size_t fsize = ftell(fp);
	fclose(fp);

	printf("Size of filename '%s' is: %ld bytes\n", fname, fsize);


	return 0;
}

