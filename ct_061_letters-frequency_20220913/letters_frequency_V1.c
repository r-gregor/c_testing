#include <stdio.h>
#include <string.h>
#include <ctype.h>

# define ENGALPHALEN 26
# define MAXCOLS 3

int main(int argc, char **argv) {

	/* TODO
	 * wchar support and test it againsta LATIN-1
	 */
	// char *s = "AAAAAAAAAAAAAjaejngšoivjnom ćxxj¸j žj žQ X KM ŽMS OHČQHFČJWERGKPWKGqjwf PNPOJNOIJoijnojnouh(&%(%=Z?UNŠJć))";
	

	char *s = "The quick brown fox jumps over the lazy dog!";
	char c;
	int s_length = strlen(s);
	char letters[ENGALPHALEN] = {0};

	printf("The characters line: \"%s\"\n", s);
	for (int i = 0; i < s_length; i++) {
		c = tolower(s[i]);
		if (c >= 'a' && c <= 'z') {
			// letters[c - 'a'] += 1;
			letters[c - 'a']++;
		}
	}
	
	int count = 0;
	for (int i = 0; i < ENGALPHALEN; i++) {
		count++;
		if (count % MAXCOLS == 0) {
			printf("Character %c: %2dx\n", 'a' + i, letters[i]);
		} else {
			printf("Character %c: %2dx\t", 'a' + i, letters[i]);
		}
	}
	printf("\n");

	return 0;
}

