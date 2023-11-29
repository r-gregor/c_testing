#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

#define MAX_ELEMENTS 10

/*
 * palindrome_casei:
 * Test if line (word) is plaindrome.
 * Fails if there are spaces between letters.
 * Works fine with letters of different case!
 */

void isPalindrome(const wchar_t *);
void printUtf8(const wchar_t *);
int caseInsCmpr(wint_t, wint_t);

/* main */
int main(int argc, char **argv) {

	setlocale(LC_CTYPE, "sl_SI.utf-8");

	const wchar_t *words[MAX_ELEMENTS] = {L"Palindrome",
							L"ABBA",
							L"A BBA",
							L"Ana",
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
		if (caseInsCmpr(line[i++], line[j--]) == 0) {
			wprintf(L"Line \"%ls\" is NOT palindrome!\n---\n", line);
			return;
		}
	}
	wprintf(L"COOL: line \"%ls\" IS palindrome.\n---\n", line);
}

int caseInsCmpr(wint_t c1, wint_t c2) {
	return towupper(c1) == towupper(c2);
}

