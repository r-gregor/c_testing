#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>


/**
 * v15
 *
 */

/*
 * TODO:
 * - sort persons by day_diff
 * - function to display top-n (day_diff <= 28 days)
 */


/* ================== GLOBALS ============================= */
time_t today;
struct tm *today_ptr;

typedef struct Date {
	int d;
	int m;
	int y;
} Date;

#include "daysdiff_v1.h" // must be after struct Date declaration because it uses it!

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
void displayPersons(Person **);
Person *makePersonFromLine(wchar_t *);
void printPerson(Person *);
void freePerson(Person *);
void release_ptr(void *);
int get_daydiff(Date *d1, Date *d2);
int getNumOfLinesFromFile(const char *filename);


/* =================== MAIN ============================== */
/** main */
int main(int argc, char **argv) {
	
	setlocale(LC_ALL, "sl_SI.utf-8");


	g_nLines = getNumOfLinesFromFile(fname);
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

	wprintf(L"Display persons:\n");
	displayPersons(persons);

	release_ptr(line);
	release_ptr(g_curr_date);
	fclose(fp);

	// test
	wprintf(L"number of lines: %ld\n", g_nLines);

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
	wprintf(L"%10ld\n", person->day_diff);
}

/**
 * Displays info [name, BDate, day_diff] for a line from file:
 * stores data from line into temporary struct person with
 * function makePersonFromLine() and prints it with
 * function printPerson().
 */

void displayPersons(Person **persons) {
	int cols = 30 + 15 + 5 + 10;
	wprintf(L"%-30ls%-15ls%-5ls%10ls\n", L"Name", L"BD", L"Age", L"Days left");
	for (int i=0; i<cols; i++) {
		wprintf(L"-");
	}
	wprintf(L"\n");

	for (int i=0; i<g_nLines; i++) {
		printPerson(persons[i]);
	}
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


