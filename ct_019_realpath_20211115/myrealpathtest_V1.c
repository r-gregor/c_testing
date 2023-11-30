#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage:\n\t%s <relative path>\n", argv[0]);
		fprintf(stderr, "You must specify a relative path.\n");
		exit(1);
	}

	printf("The real path is: %s\n", realpath(argv[1], NULL));

	return 0;
}

