#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/*
 * FROM:
 * https://man7.org/linux/man-pages/man3/getline.3.html
 */

int main(int argc, char *argv[]) {
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1) {
		/* %zd --> required for ssize_t type (nread))! */
		printf("Retrieved line of length %zd:\n", nread);
		fwrite(line, nread, 1, stdout);
		printf("\n");
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

