#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

#define MAX_ELEMENTS 9

/*
 * palindrome_casei_spci:
 * Test if line (word) is plaindrome.
 * Works fine with both spaces between letters
 * and characters of different case.
 */

void isPalindrome(const wchar_t *);
void printUtf8(const wchar_t *);
int caseInsCmpr(wint_t, wint_t);

/* main */
int main(int argc, char **argv) {

	setlocale(LC_CTYPE, "sl_SI.utf-8");

	const wchar_t *words[MAX_ELEMENTS] = {L"Palindrome",
							L"A BBA",
							L"Ana",
							L"anavolimilovana",
							L"Ana voli Milovana",
							L"popokatepetl",
							L"koteLetok",
							L"Perica reže raci rep",
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
		if (wcsncmp(&line[i], L" ", 1) == 0) {
			i++;
		}

		if (wcsncmp(&line[j], L" ", 1) == 0) {
			j--;
		}
		if (caseInsCmpr(line[i], line[j]) == 0) {
			wprintf(L"Line \"%ls\" is NOT palindrome!\n---\n", line);
			return;
		}
		i++;
		j--;
	}
	wprintf(L"COOL: line \"%ls\" IS palindrome.\n---\n", line);
}

int caseInsCmpr(wint_t c1, wint_t c2) {
	return towupper(c1) == towupper(c2);
}

