#define _POSIX_C_SOURCE 200809L // getline() !!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * v14
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
	char *name;
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
int getPositionOfDelim(char, char *);
void displayPersons(Person **);
void displayPersons2(Person **);
Person *makePersonFromLine(char *);
void printPerson(Person *);
void freePerson(Person *);
void release_ptr(void *);
int get_daydiff(Date *d1, Date *d2);
int getNumOfLinesFromFile(const char *filename);


/* =================== MAIN ============================== */
/** main */
int main(int argc, char **argv) {

	g_nLines = getNumOfLinesFromFile(fname);
	persons = malloc(sizeof(Person *) * g_nLines);
	today = time(NULL);
	today_ptr = localtime(&today);
	g_curr_date = malloc(sizeof(Date));
	g_curr_date->y = today_ptr->tm_year + 1900;
	g_curr_date->m = today_ptr->tm_mon + 1;
	g_curr_date->d = today_ptr->tm_mday;
	printf("Today: %d-%02d-%02d\n", g_curr_date->y, g_curr_date->m, g_curr_date->d);

	FILE *fp = fopen(fname, "r");
	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	char *line = NULL;
	size_t n = 0;
	ssize_t line_len = 0; // it can be -1 !

	while ((line_len = getline(&line, &n, fp)) != -1) {
		line[strcspn(line, "\n")] = 0; // Remove '\n' from the line
		persons[np] = makePersonFromLine(line);
		np++;
	}

	printf("Display persons:\n");
	displayPersons2(persons);

	release_ptr(line); // because of getline()!!
	release_ptr(g_curr_date);
	fclose(fp);

	// test
	printf("number of lines in %s: %d\n", fname, g_nLines);

	return 0;
} /* end main */


/* =========================  FUNCTION DEFINITIONS ================================== */

/**
 * Returns the position of the delimiter in a string
 */
int getPositionOfDelim(char delim, char *line) {
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
 * Displays info [name, BDate, day_diff] for a line from file:
 * stores data from line into temporary struct person with
 * function makePersonFromLine() and prints it with
 * function printPerson().
 */
void displayPersons(Person **persons) {
	for (int i=0; i<g_nLines; i++) {
		printf("ID: %d\n", i + 1);
		printPerson(persons[i]);
	}
}


void displayPersons2(Person **persons) {
	for (int i=0; i<g_nLines; i++) {
		printf("%-30s", persons[i]->name);
		printf(" %02d.%02d.%d ", persons[i]->bd_date.d, persons[i]->bd_date.m, persons[i]->bd_date.y);
		printf("%-2d", persons[i]->age);
		printf("%d\n", persons[i]->day_diff);
	}
}

/**
 * Mallocs the new 'Person' struct and populates it
 * with values in line. Frees malloc-ed Date after
 * updating person's field bd_date.
 */
Person *makePersonFromLine(char *line) {
	int curryear = g_curr_date->y;
	int pos = getPositionOfDelim(',', line);
	Person *person = malloc(sizeof(Person));
	person->name = malloc(sizeof(char) * (pos + 1));

	strcpy(person->name, strtok(line, ","));
	person->bd_date.d = atoi(strtok(NULL, "."));
	person->bd_date.m = atoi(strtok(NULL, "."));
	person->bd_date.y = atoi(strtok(NULL, "."));
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
	printf("Name: %s\n", person->name);
	printf("Birthday: %02d/%02d/%d\n", person->bd_date.d, person->bd_date.m, person->bd_date.y);
	printf("Age: %d\n", person->age);
	printf("Days diff: %d\n---\n", person->day_diff);
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
		printf("Already free!");
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


