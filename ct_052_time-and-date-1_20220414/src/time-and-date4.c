#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** v4
 * added new function printInfo() to print out info from both structs
 * uses the getPositionOfDelim() function, and all the logic
 * from main v3 with some corrections stated at the beginning
 * of function
 */

typedef struct Newdate {
	char day[3];
	char month[3];
	char year[5];
} Newdate;

typedef struct Record {
	char *name;
	char *new_date;
} Record;

int getPositionOfDelim(char, char *);
void printInfo(char *);

/** main */
int main(int argc, char **argv) {

	double diff_scnds1 = 25*365*24*3600;
	double diff_scnds2 = 4.5*365*24*3600;
	printf("span1: %9.2f\n", diff_scnds1/(365.0*24*3600));
	printf("span2: %9.2f\n", diff_scnds2/(365.0*24*3600));

	// ---------------------------------------------------
	char *line = "Gregor Redelonghi,22.02.2022";
	printInfo(line);

	char *line2 = "Tadeja Mali Redelonghi,19.01.1970";
	printInfo(line2);

	char *line3 = "Abcd Efghij Klmn Oprsšt Uvzž,22.02.2022";
	printInfo(line3);

	return 0;
 } /* end main */

/**
 * function that returns the positin of the delimiter in a string
 */
int getPositionOfDelim(char delim, char *line) {
	int pos;
	int j = 0;
	while (!line[j] == '\0') {
		if (line[j] == ',') {
			pos = j;
			break;
		} else {
			j++;
		}
	}
	return pos;
}

/**
 * new in v4
 * function that extracts [name],[date] from string
 * and prints those separately
 * uses function getPositionOfDelim() to get delimiter position
 * corrected mallocs (sizes) <-- valgrind!
 * frees all malloc-ed memory
 * corrected positional argument for '\0' character in record->name
 * from strlen[record->name] to int pos
 */
void printInfo(char *line) {
	int pos = getPositionOfDelim(',', line);
	Newdate *newdate = malloc(sizeof(Newdate));
	Record *record = malloc(sizeof(Record));
	record->name = malloc(sizeof(char) * (pos + 1));
	record->new_date = malloc(sizeof(char) * 11);

	strncpy(record->name, &line[0], pos);
	record->name[pos] = '\0';

	strncpy(newdate->day, &line[pos + 1], 2);
	newdate->day[2] = '\0';
	strncpy(newdate->month, &line[pos + 4], 2);
	newdate->month[2] = '\0';
	strncpy(newdate->year, &line[pos + 7], 4);
	newdate->year[4] = '\0';
	sprintf(record->new_date, "%s/%s/%s", newdate->day, newdate->month, newdate->year);

	printf("Name: %s\n", record->name);
	printf("Birthday: %s\n---\n", record->new_date);
	free(record->name);
	free(record->new_date);
	free(record);
	free(newdate);
}

