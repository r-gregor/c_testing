#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

void crtc(size_t n);


/* ================== GLOBALS ============================= */
const char *fname = "ROJSTNIDNEVI.txt";


/* =================== MAIN ============================== */
int main(int argc, char **argv) {
	
	setlocale(LC_ALL, "sl_SI.utf-8");

	FILE *fp = fopen(fname, "r");
	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	// wchar_t *line = NULL;
	size_t nlines = 0;
	wchar_t *line = malloc(sizeof(wchar_t) * 100);
	wchar_t *name = malloc(sizeof(wchar_t) * 50);
	wchar_t *date = malloc(sizeof(wchar_t) * 11);

	wchar_t *date2 = L"20.12.2022";
	int f1, f2, cols;

	f1 = 30;
	f2 = 15;
	cols = f1 + f2 + 10;

	wprintf(L"%-*ls%-*ls%ls\n", f1, L"Name", f2, L"BD", L"Date2");
	crtc(cols);

	while (fgetws(line, 100, fp) != NULL) {
		line[wcscspn(line, L"\n")] = 0; // Remove '\n' from the line

	/*
	 * 		// option 1
	 *  		wprintf(L"%ls\n", line);
	 * 		nlines++;
	 */

		// option 2
		wchar_t *ptr;
		name = wcstok(line, L",", &ptr);
		date = wcstok(NULL, L",", &ptr);
		
		wprintf(L"%-*ls%-*ls%ls\n", f1, name, f2, date, date2);
		nlines++;
	}


	wprintf(L"Number of lines printed: %ld\n", nlines);

	fclose(fp);

	// free(line);
	// free(name);
	// free(date);

	return 0;
} /* end main */

void crtc(size_t n) {
	for (int i=0; i<n; i++) {
		wprintf(L"-");
	}
	wprintf(L"\n");
}

