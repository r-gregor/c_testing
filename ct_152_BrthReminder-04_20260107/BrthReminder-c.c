/*
 * BrthReminder_c.c
 * v22: remove function wcstok() for tokenizing, because mingW could not compile
 *      into win native executable. Running in cmd still not showing "čšž" properly
 *      Go version works well (go for win)
 *      wcstok() function replaced by char by char copy, and swprintf() function to
 *      conwert wchar_t chars into integers
 *
 * v23: wcscasecmp instead of wcssmp in main() for case insensitive comparisson
 * v24: check for part of the name (case insesitive)
 * v25: 20241121: get realpath to set absolute path to ROJSTNIDNEVI.txt file
 *                so no probems with softlinking
 * v26: 20241206: moved all time and date related structs and globals into daysdiff.h
 * v27: 20260107: remove duplicates from printout and report number of duplicates found
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <limits.h>
#include "daysdiff.h"

#define _XOPEN_SOURCE 500

/* ================== GLOBALS ============================= */
typedef struct Person {
	wchar_t *name;
	Date bd_date;
	int age;
	int day_diff;
} Person_t;

const char *fname = "ROJSTNIDNEVI.txt";
Date *g_curr_date;
int g_nLines = 0;
Person_t **persons_unsorted;
Person_t **persons;
int np = 0;
int dups = 0;
size_t pers_count = 0;

/* ================== FUNCTION DECLARATIONS ============== */
int getPositionOfDelim(wchar_t, wchar_t *);
void displayPersonsAll(Person_t **);
void displayPersonsDiff100(Person_t **persons);
void displayPersonsIfFound(Person_t **persons, wchar_t *searchp); // v24
void wcs_to_lower(wchar_t *source, wchar_t *dest);                // v24
Person_t *makePersonFromLine(wchar_t *);
void printPerson(Person_t *);
void freePerson(Person_t *);
void release_ptr(void *);
int get_daydiff(Date *, Date *);
int getNumOfLinesFromFile(const char *);
int cmpfunc_daysdiff(const void *, const void *);                 // v27
int cmpfunc_name(const void *, const void *);                     // v27
void crtc(int n);
char *abspath(char *argv0);

/* =================== MAIN ============================== */
/** main */
int main(int argc, char **argv) {
	
	// setlocale(LC_ALL, "sl_SI.utf-8");
	setlocale(LC_ALL, "");

	char path0[256];                           // v25
	char path1[256];
	realpath(argv[0], path0);                  // v25
	strcpy(path1, abspath(path0));             // v25 - just path without filename
	strcat(path1, "/");
	strcat(path1, fname);

	g_nLines = getNumOfLinesFromFile(path1);
	persons_unsorted = malloc(sizeof(Person_t *) * g_nLines);    // v27
	
	today = time(NULL);
	today_ptr = localtime(&today);
	g_curr_date = malloc(sizeof(Date));
	g_curr_date->y = today_ptr->tm_year + 1900;
	g_curr_date->m = today_ptr->tm_mon + 1;
	g_curr_date->d = today_ptr->tm_mday;
	wprintf(L"Today: %ld-%02ld-%02ld\n", g_curr_date->y, g_curr_date->m, g_curr_date->d);

	FILE *fp = fopen(fname, "r");
	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	wchar_t *line = malloc(sizeof(wchar_t) * 100);

	while (fgetws(line, 100, fp) != NULL) {
		line[wcscspn(line, L"\n")] = 0; // Remove '\n' from the line
		  persons_unsorted[np] = makePersonFromLine(line);                 // v27
		np++;
	}

	qsort(persons_unsorted, g_nLines, sizeof(Person_t *), cmpfunc_name);   // V27

	// v27
	for (int i=1; i < g_nLines; i++) {
		if (wcscmp(persons_unsorted[i]->name, persons_unsorted[i-1]->name) == 0) {
			continue;
		} else {
			pers_count++;
		}
	}

	// v27
	persons = malloc(sizeof(Person_t *) * pers_count);
	persons[0] = persons_unsorted[0];
	int k=0;
	for (int i=1; i < g_nLines; i++) {
		if (wcscmp(persons_unsorted[i]->name, persons_unsorted[i-1]->name) == 0) {
			dups++;
			continue;
		} else {
			persons[++k] = persons_unsorted[i];
		}
	}

	/* qsort ... */
	qsort(persons, pers_count, sizeof(Person_t *), cmpfunc_daysdiff);    // v27
	
	if (argc == 2) {
		wchar_t wans[256] = {L'0'};
		mbstowcs(wans, argv[1], 256);
		if (wcscasecmp(wans, L"ALL") == 0) { // v23
			displayPersonsAll(persons);
		} else {
			displayPersonsIfFound(persons, wans);
		}
	} else {
		displayPersonsDiff100(persons);
	}



	release_ptr(line);
	release_ptr(g_curr_date);
	fclose(fp);

	// v27
	for (int i=1; i < g_nLines; i++) {
		release_ptr(persons_unsorted[i]->name);
		release_ptr(persons_unsorted[i]);
	}

	release_ptr(persons_unsorted);    // v27

	return 0;
} /* end main */


/* =========================  FUNCTION DEFINITIONS ================================== */


/**
 * Returns the position of the delimiter in a string
 */
int getPositionOfDelim(wchar_t delim, wchar_t *line) {
	int pos = 0;
	int j = 0;
	while (line[j] != '\0') {
		if (line[j] == delim) {
			pos = j;
			break;
		} else {
			j++;
		}
	}
	return pos;
}


/**
 * Mallocs the new 'Person' struct and populates it
 * with values in line. Frees malloc-ed Date after
 * updating person's field bd_date.
 */
Person_t *makePersonFromLine(wchar_t *line) {
	int curryear = g_curr_date->y;
	int pos = getPositionOfDelim(',', line);
	Person_t *person = malloc(sizeof(Person_t));
	person->name = malloc(sizeof(wchar_t) * (pos + 1));

	wchar_t* ptr;
	wchar_t * pEnd;
	wcscpy(person->name, wcstok(line, L",", &ptr));
	person->bd_date.d = wcstol(wcstok(NULL, L".", &ptr), &pEnd, 10);
	person->bd_date.m = wcstol(wcstok(NULL, L".", &ptr), &pEnd, 10);
	person->bd_date.y = wcstol(wcstok(NULL, L".", &ptr), &pEnd, 10);
	person->age = curryear - person->bd_date.y;

	Date this_year = {person->bd_date.d, person->bd_date.m, g_curr_date->y};

	if (getDifference(g_curr_date, &this_year) < 0) {
		this_year.y +=1;
	}
	person->day_diff = getDifference(g_curr_date, &this_year);
	// line = NULL;

	return person;
}

/**
 * Prints formated contents of updated person.
 */
void printPerson(Person_t *person) {
	wprintf(L"%-30ls", person->name);
	wprintf(L"%02ld.%02ld.%ld     ", person->bd_date.d, person->bd_date.m, person->bd_date.y);
	wprintf(L"%-5ld", person->age);

	wchar_t asap[6] =                                                 L"     ";
	if (person->day_diff < 3)                            wcscpy(asap, L"  ***");
	if (person->day_diff >= 3 && person->day_diff <= 8)  wcscpy(asap, L"   **");
	if (person->day_diff >= 8 && person->day_diff <= 21) wcscpy(asap, L"    *");
	
	wprintf(L"%ls%5ld\n", asap, person->day_diff);
}


/**
 * Display ALL persons sorted by days till BD
 * lowest to heighest
 * v27: new range 0 --> pers_count
 */

void displayPersonsAll(Person_t **persons) {
	int cols = 30 + 15 + 5 + 10;
	wprintf(L"%-30ls%-15ls%-5ls%10ls\n", L"Name", L"BD", L"Age", L"Days left");
	for (int i=0; i<cols; i++) {
		wprintf(L"-");
	}
	wprintf(L"\n");

	for (int i=0; i < pers_count; i++) {
		printPerson(persons[i]);
	}
	crtc(cols);

	if (dups > 0) {
		wprintf(L"Duplicates found: %d\n", dups);
	}
	wprintf(L"Displaying ALL persons sorted by days till BD\n\n");
}


/**
 * display persons with less than 100 days till BD
 * v27: new range 0 --> pers_count
 */
void displayPersonsDiff100(Person_t **persons) {
	int cols = 30 + 15 + 5 + 10;
	crtc(cols);
	wprintf(L"%-30ls%-15ls%-5ls%10ls\n", L"Name", L"BD", L"Age", L"Days left");
	crtc(cols);

	for (int i=0; i < pers_count; i++) {
		if (persons[i]->day_diff <= 100) {
			printPerson(persons[i]);
		}
	}
	crtc(cols);

	if (dups > 0) {
		wprintf(L"Duplicates found: %d\n", dups);
	}
	wprintf(L"Displaying persons with less than 100 days till BD\n\n");
}

/**
 * display persons whose name contains search pattern
 * v27: new range 0 --> pers_count
 */
void displayPersonsIfFound(Person_t **persons, wchar_t *searchp) {
	int cols = 30 + 15 + 5 + 10;
	crtc(cols);
	wprintf(L"%-30ls%-15ls%-5ls%10ls\n", L"Name", L"BD", L"Age", L"Days left");
	crtc(cols);
	wchar_t searchp_lc[256] = {L'\0'};
	wcs_to_lower(searchp, searchp_lc);

	for (int i=0; i < pers_count; i++) {
		wchar_t name_lc[256] = {L'\0'};
		wcs_to_lower(persons[i]->name, name_lc);

		if (wcsstr(name_lc, searchp_lc) != NULL) {
		// if (wcsstr(wsrc, wdest) != NULL) {
			printPerson(persons[i]);
		}
	}
	crtc(cols);

	if (dups > 0) {
		wprintf(L"Duplicates found: %d\n", dups);
	}
	wprintf(L"Displaying persons with '%ls' pattern in name\n\n", searchp);

}

/**
 * dro a lin of n "-"s
 */
void crtc(int n) {
	for (int i=0; i<n; i++) {
		wprintf(L"-");
	}
	wprintf(L"\n");
}

/**
 * Frees malloc-ed contents of 'person' struct.
 */
void freePerson(Person_t *person) {
	release_ptr(person->name);
	release_ptr(person);
}

/**
 * free a pointer and set it to NULL
 */
void release_ptr(void *ptr) {
	if (ptr == NULL) {
		wprintf(L"Already free!");
		exit(EXIT_SUCCESS);
	}

	free(ptr);
	ptr = NULL;
}


/**
 * store number of lines from file
 * into global variable
 */
int getNumOfLinesFromFile(const char *filename){
	FILE* fp = fopen(filename, "r");

	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	int ch, number_of_lines = 0;

	do {
		ch = fgetc(fp);
		if(ch == '\n')
			number_of_lines++;
	}
	while (ch != EOF);

	fclose(fp);
	
	return number_of_lines;
}


/**
 * coparison function for qsort -- daysdiff
 */
int cmpfunc_daysdiff(const void *a, const void *b) {

    Person_t *pA = *(Person_t **)a;
    Person_t *pB = *(Person_t **)b;

	// smallest to biggest
    return (pA->day_diff - pB->day_diff);
}

/**
 * coparison function for qsort -- name
 */
int cmpfunc_name(const void *a, const void *b) {

    Person_t *pA = *(Person_t **)a;
    Person_t *pB = *(Person_t **)b;

	// strings compare
    return wcscmp(pA->name, pB->name);
}
// ##############################################################################################


char *abspath(char *argv0) {
	char path_save[PATH_MAX];
	char abs_exe_path[PATH_MAX];
	char *p;
	char *abspth;

	if(!(p = strrchr(argv0, '/'))) {
		getcwd(abs_exe_path, sizeof(abs_exe_path));
	} else {
		*p = '\0';
		getcwd(path_save, sizeof(path_save));
		chdir(argv0);
		getcwd(abs_exe_path, sizeof(abs_exe_path));
	}

	abspth = abs_exe_path;
	return abspth;
}

/*
 * need to initialize the dest string as:
 *     wchar_t *dest[SIZE] = {L'\0'};
 */
void wcs_to_lower(wchar_t *source, wchar_t *dest) {
	for (int i = 0; i < wcslen(source); i++) {
		dest[i] = towlower(source[i]);
	}
}
