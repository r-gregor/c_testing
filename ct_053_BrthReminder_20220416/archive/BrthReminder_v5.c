#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * v5
 * added time.h to display current time and calculate year difference (age)
 */

/**
 * TODO:
 * typedef struct Person {
 * 	char *name;
 * 	char *date_of_birth;
 * 	char *curr_date; //??
 * 	int  *age;
 * 	int  *daydiff;
 * } Person;
 */

time_t today;
struct tm *todayp;

typedef struct Newdate {
	char day[3];
	char month[3];
	char year[5];
} Newdate;

typedef struct Record {
	char *name;
	char *new_date;
	int ydiff;                    /* v5 */
} Record;

const char *fname = "ROJSTNIDNEVI.txt";

int getPositionOfDelim(char, char *);
void displayRecordInfo(char *);
void updateRecordInfo(char *, Record *);
void printRecord(Record *);
void freeRecord(Record *);

/** main */
int main(int argc, char **argv) {

	today = time(NULL);           /* v5 */
	todayp = localtime(&today);   /* v5 */

	FILE *fp = fopen(fname, "r");
	if(!fp) {
		perror("ERROR");
		return EXIT_FAILURE;
	}

	char *line = NULL;
	size_t n = 0;
	size_t nLines = 0;
	ssize_t line_len = 0;

	while ((line_len = getline(&line, &n, fp)) != -1) {
		nLines += 1;
		// Remove \n from the line.
		line[strcspn(line, "\n")] = 0;
		displayRecordInfo(line);
	}
	free(line); // because of getline()!!
	fclose(fp);

	return 0;
} /* end main */

/**
 * Returns the position of the delimiter in a string
 */
int getPositionOfDelim(char delim, char *line) {
	int pos;
	int j = 0;
	while (!line[j] == '\0') {
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
 * function updateRecordInfo() and prints it with
 * function printRecord().
 */
void displayRecordInfo(char *line) {
	Record *person = malloc(sizeof(Record));
	updateRecordInfo(line, person);
	printRecord(person);
	freeRecord(person);
}

/**
 * Mallocs the new 'record' struct and populates it
 * with values in line. Frees malloc-ed newdate after
 * updating record's field new_date.
 */
void updateRecordInfo(char *line, Record *record) {
	int curryear = todayp->tm_year + 1900;
	int pos = getPositionOfDelim(',', line);
	Newdate *newdate = malloc(sizeof(Newdate));
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
	record->ydiff = curryear - (atoi(newdate->year));
	free(newdate);
}

/**
 * Prints formated contents of updated record.
 */
void printRecord(Record *record) {
	printf("Name: %s\n", record->name);
	printf("Birthday: %s\n", record->new_date);
	printf("Age: %d\n---\n", record->ydiff); /* v5 */
}

/**
 * Frees malloc-ed contents of 'record' struct.
 */
void freeRecord(Record *record) {
	free(record->name);
	free(record->new_date);
	free(record);
}

