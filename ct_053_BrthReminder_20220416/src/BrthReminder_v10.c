#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * v10
 * struct Newdate --> Date {int d, int m, int y}
 *
 */

time_t today;
struct tm *today_ptr;

typedef struct Date {
	int d;
	int m;
	int y;
} Date;

typedef struct Person {
	char *name;
	char *bd_date;
	int *age;
	int *day_diff;
} Person;

const char *fname = "ROJSTNIDNEVI.txt";
Date *curr_date; // v10

int getPositionOfDelim(char, char *);
void displayPersonInfo(char *);
void updatePersonInfo(char *, Person *);
void printPerson(Person *);
void freePerson(Person *);
void release_ptr(void *);            /* v8 */

/** main */
int main(int argc, char **argv) {

	today = time(NULL);

	// v10
	today_ptr = localtime(&today);
	curr_date = malloc(sizeof(Date));
	curr_date->y = today_ptr->tm_year + 1980;
	curr_date->m = today_ptr->tm_mon + 1;
	curr_date->d = today_ptr->tm_mday;
	printf("Today: %d-%02d-%02d\n", curr_date->y, curr_date->m, curr_date->d);

	FILE *fp = fopen(fname, "r");
	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	char *line = NULL;
	size_t n = 0;
	size_t nLines = 0;
	ssize_t line_len = 0; // it can be -1 !

	while ((line_len = getline(&line, &n, fp)) != -1) {
		nLines += 1;
		// Remove \n from the line.
		line[strcspn(line, "\n")] = 0;
		displayPersonInfo(line);
	}

	// v10
	// free(line); // because of getline()!!
	release_ptr(line);      // because of getline()!!
	release_ptr(curr_date); // v10
	fclose(fp);

	return 0;
} /* end main */

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
 * Displays info [Name, BDate] for a line from file:
 * stores data from line into temporary struct person with
 * function updatePersonInfo() and prints it with
 * function printPerson().
 */
void displayPersonInfo(char *line) {
	Person *person = malloc(sizeof(Person));
	updatePersonInfo(line, person);
	printPerson(person);
	freePerson(person);
}

/**
 * Mallocs the new 'person' struct and populates it
 * with values in line. Frees malloc-ed Date after
 * updating person's field bd_date.
 */
void updatePersonInfo(char *line, Person *person) {
	// int curryear = today_ptr->tm_year + 1900;
	int curryear = curr_date->y;
	int pos = getPositionOfDelim(',', line);
	Date *newdate = malloc(sizeof(Date));
	person->name = malloc(sizeof(char) * (pos + 1));
	person->bd_date = malloc(sizeof(char) * 11);
	person->day_diff = malloc(sizeof(int)); // v10

	strcpy(person->name, strtok(line, ","));
	/*
	 * V10
	strcpy(newdate->day, strtok(NULL, "."));
	strcpy(newdate->month, strtok(NULL, "."));
	strcpy(newdate->year, strtok(NULL, "."));
	*/

	// v10
	newdate->d = atoi(strtok(NULL, "."));
	newdate->m = atoi(strtok(NULL, "."));
	newdate->y = atoi(strtok(NULL, "."));
	line = NULL;

	/*
	 * v10
	sprintf(person->bd_date, "%s/%s/%s", newdate->d, newdate->m, newdate->y);
	 */

	// v10
	sprintf(person->bd_date, "%d/%d/%d", newdate->d, newdate->m, newdate->y);
	person->age = malloc(sizeof(int *));
	*(person->age) = curryear - (newdate->y);

	free(newdate);
}

/**
 * Prints formated contents of updated person.
 */
void printPerson(Person *person) {
	printf("Name: %s\n", person->name);
	printf("Birthday: %s\n", person->bd_date); // v10
	printf("Age: %d\n---\n", *(person->age));  // v10
}

/**
 * Frees malloc-ed contents of 'person' struct.
 */
void freePerson(Person *person) {
	release_ptr(person->name);
	release_ptr(person->bd_date);
	release_ptr(person->age);
	release_ptr(person);

}

void release_ptr(void *ptr) {
	if (ptr == NULL) {
		printf("Already free!");
		exit(EXIT_SUCCESS);
	}

	free(ptr);
	ptr = NULL;
}


