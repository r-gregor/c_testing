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

// v20

/* ================== GLOBALS ============================= */
time_t today;
struct tm *today_ptr;

typedef struct Person {
	wchar_t *name;
	Date bd_date;
	int age;
	int day_diff;
} Person;

const char *fname = "ROJSTNIDNEVI.txt";
Date *g_curr_date;
int g_nLines = 0;
Person **persons;
int np = 0;

/* ================== FUNCTION DECLARATIONS ============== */
int getPositionOfDelim(wchar_t, wchar_t *);
void displayPersonsAll(Person **);
void displayPersonsDiff100(Person **persons);
Person *makePersonFromLine(wchar_t *);
void printPerson(Person *);
void freePerson(Person *);
void release_ptr(void *);
int get_daydiff(Date *, Date *);
int getNumOfLinesFromFile(const char *);
int cmpfunc(const void *, const void *);
void crtc(int);
char *abspath(char *);

/* =================== MAIN ============================== */
/** main */
int main(int argc, char **argv) {
	
	setlocale(LC_ALL, "sl_SI.utf-8");

	char path1[PATH_MAX];
	// wchar_t path2[PATH_MAX];
	strcpy(path1, abspath(argv[0]));
	strcat(path1, "/");
	strcat(path1, fname);
	// mbstowcs(path2, path1, 256);
	// wprintf(L"%ls\n", path2);

	g_nLines = getNumOfLinesFromFile(path1);
	persons = malloc(sizeof(Person *) * g_nLines);
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
		persons[np] = makePersonFromLine(line);
		np++;
	}

	/* qsort ... */
	qsort(persons, g_nLines, sizeof(Person *), cmpfunc);
	
	// v19
	if (argc == 2 && strlen(argv[1]) < 4) {
		wchar_t wans[4];
		// size_t numwchars;
		mbstowcs(wans, argv[1], 4);
		if (wcscmp(wans, L"ALL") == 0) {
			displayPersonsAll(persons);
		} else {
			displayPersonsDiff100(persons);
		}
	} else {
		displayPersonsDiff100(persons);
	}

	fclose(fp);
	
	release_ptr(line);
	release_ptr(g_curr_date);

	for (int i=0; i < g_nLines; i++) {
		freePerson(persons[i]);
	}
	release_ptr(persons);

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
Person *makePersonFromLine(wchar_t *line) {
	int curryear = g_curr_date->y;
	int pos = getPositionOfDelim(',', line);
	Person *person = malloc(sizeof(Person));
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
void printPerson(Person *person) {
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
 */

void displayPersonsAll(Person **persons) {
	int cols = 30 + 15 + 5 + 10;
	wprintf(L"%-30ls%-15ls%-5ls%10ls\n", L"Name", L"BD", L"Age", L"Days left");
	for (int i=0; i<cols; i++) {
		wprintf(L"-");
	}
	wprintf(L"\n");

	for (int i=0; i<g_nLines; i++) {
		printPerson(persons[i]);
	}
	crtc(cols);
	wprintf(L"Displaying ALL persons sorted by days till BD\n");
}


/**
 * display persons with less than 100 days till BD
 */
void displayPersonsDiff100(Person **persons) {
	int cols = 30 + 15 + 5 + 10;
	crtc(cols);
	wprintf(L"%-30ls%-15ls%-5ls%10ls\n", L"Name", L"BD", L"Age", L"Days left");
	crtc(cols);

	for (int i=0; i<g_nLines; i++) {
		if (persons[i]->day_diff <= 100) {
			printPerson(persons[i]);
		}
	}
	crtc(cols);
	wprintf(L"Displaying persons with less than 100 days till BD\n");
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
void freePerson(Person *person) {
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
 * coparison function fro qsort
 */
int cmpfunc(const void *a, const void *b) {

    Person *pA = *(Person **)a;
    Person *pB = *(Person **)b;

	// smallest to biggest
    return (pA->day_diff - pB->day_diff);
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

