#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

#define MAX_ELEMENTS 10

/*
 * palindrome:
 * Test if line (word) is plaindrome.
 * Fails if charcters are of different case, or
 * if there are spaces between letters.
 */

void isPalindrome(const wchar_t *);
void printUtf8(const wchar_t *);

/* main */
int main(int argc, char **argv) {

	setlocale(LC_CTYPE, "sl_SI.utf-8");

	const wchar_t *words[MAX_ELEMENTS] = {L"Palindrome",
							L"ABBA",
							L"A BBA",
							L"ana",
							L"anavolimilovana",
							L"AnavoliMilovana",
							L"popokatepetl",
							L"koteLetok",
							L"Pericarežeracirep",
							L"timbuktu"
	};

	for (int k=0; k < MAX_ELEMENTS; k++) {
		isPalindrome(words[k]);

		/* test
		printUtf8(words[k]);
		*/
	}

	return 0;
} // end main

void isPalindrome(const wchar_t *line) {
	int i = 0;
	int j = wcslen(line) - 1;

	while (j >= i) {
		if (wcsncmp(&line[i++], &line[j--], 1) != 0) {
			wprintf(L"Line \"%ls\" is NOT palindrome!\n---\n", line);
			return;
		}
	}
	wprintf(L"COOL: line \"%ls\" IS palindrome.\n---\n", line);
}

/* test
void printUtf8(const wchar_t *line) {
	wprintf(L"Line: \"%ls\"\n", line);
}
*/

