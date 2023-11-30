#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 12

void isItPalindrome( char *);

/**
 * main
 */
int main(int argc, char **argv) {

	/* creful: only 12 words allowed! */
	char *words[ARRAY_SIZE] = {	"abracadabra", 
								"ana",
								"kukulelle",
								"ABBA",
								"abutuba",
								"pericarežeracirep",
								"KAMASUTRA",
								"kaaZaak",
								"anavolimilovana",
								"ja aj" "JA JA",
								"pericarezeracirep"
								};


	for (size_t k = 0; k < ARRAY_SIZE - 1; k++) {
		isItPalindrome(words[k]);
	}


	return 0;
}

/**
 * function isItPalindrome(string)
 */
void isItPalindrome(char *line) {
	int i = 0;
	int j = strlen(line) - 1;

	while (j >= i) {
		if (line[i++] != line[j--])  {
			printf("SORRY: the word: \"%s\" is NOT palindrome.\n---\n", line);
			return;
		}
	}
	printf("*** HURRAY!! The word: \"%s\" IS palindrome!*** \n---\n", line);
}

