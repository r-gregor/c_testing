#include <stdio.h>
#include <string.h>

/* v2: add tokens to an array of strings */
int main(int argc, char **argv) {



	char line1[] = "Venom.2.Let.there.be.carnage.2021.mp4";
	char delim[4] = ".";
	char *tokens[25];

	printf(" --- strok() function test-2 [20211128] ---\n");
	printf("Test line: \"%s\"\n\n", line1);

	int i = 0;
	tokens[i] = strtok(line1, delim);

	while (tokens[i] != NULL) {
		i++;
		tokens[i] = strtok(NULL, delim);
	}


	/* print the contents of an array */
	for (int j=0; j<i; j++) {
		printf("token-%d: %s\n", j+1, tokens[j]);
	}

	return 0;
}

