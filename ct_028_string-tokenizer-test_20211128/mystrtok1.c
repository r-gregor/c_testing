#include <stdio.h>
#include <string.h>

/* v1: print the tokens to the screen*/
int main(int argc, char **argv) {

	char line1[] = "Venom.2.Let.there.be.carnage.2021.mp4";
	char *token;
	char delim[4] = ".";

	printf(" --- strok() function test-1 [20211128] ---\n");
	printf("Test line: \"%s\"\n\n", line1);

	token = strtok(line1, delim);
	// printf("1-st token: %s\n", token);

	int counter = 0;
	while (token != NULL) {
		/* must be before subsequent line, or 'token: NULL' will be printed! */
		/* it also prints the first token from previous strok()*/
		counter++;
		printf("token-%d: %s\n", counter, token);
		token = strtok(NULL, delim);
	}


	return 0;
}

