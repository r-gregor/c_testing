#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** v3
 * added new struct for newdate
 * finding position of delim in separate function getPositionOfDelim()
 */

typedef struct Record {
	char *name;
	char *new_date;
} Record;

typedef struct Newdate {
	char day[3];
	char month[3];
	char year[5];
} Newdate;

int getPositionOfDelim(char, char *);

/** main */
int main(int argc, char **argv) {

	double diff_scnds1 = 25*365*24*3600;
	double diff_scnds2 = 4.5*365*24*3600;
	printf("span1: %9.2f\n", diff_scnds1/(365.0*24*3600));
	printf("span2: %9.2f\n", diff_scnds2/(365.0*24*3600));

	// ---------------------------------------------------
	char *olddatestr = "22.02.1968";

	Newdate *newdate = malloc(sizeof(newdate));

	strncpy(newdate->day, &olddatestr[0], 2);
	newdate->day[2] = '\0';
	strncpy(newdate->month, &olddatestr[3], 2);
	newdate->month[2] = '\0';
	strncpy(newdate->year, &olddatestr[6], 4);
	newdate->year[4] = '\0';

	printf("Date: %s-%s-%s\n", newdate->year, newdate->month, newdate->day);

	// ---------------------------------------------------
	printf("Find the position of comma in a line with <WHILE loop>:\n");
	char *line = "Gregor Redelonghi,22.02.2022";
	int pos = getPositionOfDelim(',', line);
	printf("The position of ',' in '%s' is: %d\n", line ,pos);
	strncpy(newdate->day, &line[pos + 1], 2);
	newdate->day[2] = '\0';
	strncpy(newdate->month, &line[pos + 4], 2);
	newdate->month[2] = '\0';
	strncpy(newdate->year, &line[pos + 7], 4);
	newdate->year[4] = '\0';
	
	printf("New date: %s/%s/%s\n", newdate->day, newdate->month, newdate->year);

	// ---------------------------------------------------
	char *line2 = "Tadeja Mali Redelonghi,19.01.1970";
	int pos2 = getPositionOfDelim(',', line2);
	Record *record = malloc(sizeof(Record));
	record->name = malloc(sizeof(char) * (pos2 + 1));
	record->new_date = malloc(sizeof(char) * 11);

	strncpy(record->name, &line2[0], pos2);
	record->name[strlen(record->name)] = '\0';

	strncpy(newdate->day, &line2[pos2 + 1], 2);
	newdate->day[2] = '\0';
	strncpy(newdate->month, &line2[pos2 + 4], 2);
	newdate->month[2] = '\0';
	strncpy(newdate->year, &line2[pos2 + 7], 4);
	newdate->year[4] = '\0';
	sprintf(record->new_date, "%s/%s/%s", newdate->day, newdate->month, newdate->year);

	printf("record->name: %s\n", record->name);
	printf("record->new_date: %s\n", record->new_date);
	free(record->name);
	free(record->new_date);
	free(record);
	free(newdate);

	return 0;
 } /* end main */

/**
 * new function in v3
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

