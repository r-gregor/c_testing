#include <stdio.h>
#include <string.h>
#include <ctype.h>

# define ENGALPHALEN 26
# define MAXCOLS 3

/* v2
 * added count of all the chars in line
 */

int numOfChars(char arr[ENGALPHALEN]);
void sep();

int main(int argc, char **argv) {

	/* TODO
	 * wchar support and test it againsta LATIN-1
	 */
	// char *s = "AAAAAAAAAAAAAjaejngšoivjnom ćxxj¸j žj žQ X KM ŽMS OHČQHFČJWERGKPWKGqjwf PNPOJNOIJoijnojnouh(&%(%=Z?UNŠJć))";
	

	char *s = "The quick brown fox jumps over the lazy dog!";
	char c;
	int s_length = strlen(s);
	char letters[ENGALPHALEN] = {0};

	printf("\nThe characters line: \"%s\"\n", s);
	sep();
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
			printf("alphabet[%02d] %c: %2dx\n", i + 1, 'a' + i, letters[i]);
		} else {
			printf("alphabet[%02d] %c: %2dx\t", i + 1,  'a' + i, letters[i]);
		}
	}
	printf("\n");
	sep();
	printf("Num of chars (without white spaces): %d\n", numOfChars(letters));
	sep();

	return 0;
}

int numOfChars(char arr[ENGALPHALEN]) {
	int sum = 0;
	for (int i = 0; i < ENGALPHALEN; i++) {
		sum += arr[i];
	}
	return sum;
}

void sep() {
	printf("---\n");
}

