#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* from:
 * filename: c_build-array-of-strings-from-file_20211129.txt
 * https://dev-notes.eu/2019/07/Build-an-Array-of-Strings-From-a-File-in-C/
 *
 * gives same printout (and approx same times):
 * $> time bin/readfintoarr.exe tiles.txt
 * $> time cat -n tiles.txt
 */

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Please supply a file path:\n%s <file path>\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *fp = fopen(argv[1], "r");
	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	// Read lines from file, allocate memory and build an array of lines
	// -----------------------------------------------------------------
	char *lineBuf = NULL;
	size_t n = 0;
	size_t nLines = 0;
	ssize_t lineLength = 0;
	size_t sizeIncrement = 10;
	char **lines = malloc(sizeIncrement * sizeof(char**));
	size_t i = 0;
	while ((lineLength = getline(&lineBuf, &n, fp)) != -1) {
		// Memory reallocation is expensive - don’t reallocate on every iteration.
		if (i >= sizeIncrement) {
			sizeIncrement += sizeIncrement;
			
			// Don’t just overwrite with realloc - the original
			// pointer may be lost if realloc fails.
			char **tmp = realloc(lines, sizeIncrement * sizeof(char**));
			if (!tmp) {
				perror("realloc");
				return EXIT_FAILURE;
			}
			lines = tmp;
		}

		// Remove \n from the line.
		lineBuf[strcspn(lineBuf, "\n")] = 0;

		// Allocate space on the heap for the line.
		*(lines + i) = malloc((lineLength + 1) * sizeof(char));

		// Copy the getline buffer into the new string.
		strcpy(*(lines + i), lineBuf);
		i++;

		// Keep track of the number of lines read for later use.
		nLines = i;
	}

	// Do something with the array of strings.
	printf("nLines: %lu\n", nLines);
	for (size_t k = 0; k < nLines; k++) {
		printf("%6lu  %s\n", k+1, *(lines + k));
	}

	// Free the buffer utilised by ‘getline()‘.
	free(lineBuf);

	// Free the array of strings.
	for (size_t i = 0; i < nLines; i++)
		free(*(lines + i));

	free(lines);
	fclose(fp);
	return 0;
}

