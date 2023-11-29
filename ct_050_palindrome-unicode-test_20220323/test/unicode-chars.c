#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char **argv) {

	setlocale(LC_CTYPE, "sl_SI.utf-8");
	wchar_t *s1 = L"Žaba";
	wchar_t *s2 = L"Žaba";

	if (wcscmp(s1, s2) == 0) {
		wprintf(L"String s1: %ls and s2: %ls are the same!\n", s1, s2);
	} else {
		wprintf(L"String s1: %ls and s2: %ls are NOT the same!\n", s1, s2);
	};

	wchar_t *abc = L"abcčdefghijklmnoprsštuvzž";
	wchar_t *ABC = L"ABCČDEFGHIJKLMNOPRSŠTUVZŽ";

	wprintf(L"abc = %ls\n", abc);
	wprintf(L"ABC = %ls\n", ABC);

	size_t len_ABC = wcslen(ABC);
	wprintf(L"Length of abc: %ld\n", len_ABC);

	wprintf(L"The first char of ABC is: %lc\n", ABC[0]);
	wprintf(L"The last char of ABC is: %lc\n", ABC[len_ABC - 1]);

	return 0;
}

