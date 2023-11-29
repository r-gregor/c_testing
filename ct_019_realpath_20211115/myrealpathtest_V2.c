#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("\n\tUsage:\t%s <relative path>\n", argv[0]);
		fprintf(stderr, "\t\t[You must specify a relative path]\n\n");
		/* exit(1); */
		return 1;
	}

	char *fullpath = realpath(argv[1], NULL);

	printf("%s\n", fullpath);
	
	free(fullpath);

	return 0;
}

