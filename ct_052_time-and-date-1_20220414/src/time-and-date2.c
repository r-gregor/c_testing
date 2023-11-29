#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** v2 
 * all in main
 * find the position of delim with WHILE loop
 */


typedef struct Mami {
	char *name;
	char *new_date;
} Mami;

/** main */
int main(int argc, char **argv) {

	double diff_scnds1 = 25*365*24*3600;
	double diff_scnds2 = 4.5*365*24*3600;
	printf("span1: %9.2f\n", diff_scnds1/(365.0*24*3600));
	printf("span2: %9.2f\n", diff_scnds2/(365.0*24*3600));

	// ---------------------------------------------------
	char *olddatestr = "22.02.1968";
	char day[3];
	char month[3];
	char year[5];

	strncpy(day, &olddatestr[0], 2);
	day[2] = '\0';
	strncpy(month, &olddatestr[3], 2);
	month[2] = '\0';
	strncpy(year, &olddatestr[6], 4);
	year[4] = '\0';

	printf("Date: %s-%s-%s\n", year, month, day);

	// ---------------------------------------------------
	printf("Find the position of comma in a line with <WHILE loop>:\n");
	char *line = "Gregor Redelonghi,22.02.2022";
	int pos;
	// while loop
	int i = 0;
	while (!line[i] == '\0') {
		if (line[i] == ',') {
			pos = i;
			break;
		} else {
			i++;
		}
	}

	printf("The position of ',' in '%s' is: %d\n", line ,pos);
	strncpy(day, &line[pos + 1], 2);
	day[2] = '\0';
	strncpy(month, &line[pos + 4], 2);
	month[2] = '\0';
	strncpy(year, &line[pos + 7], 4);
	year[4] = '\0';
	
	printf("New date: %s/%s/%s\n", day, month, year);

	// ---------------------------------------------------
	char *line2 = "Tadeja Mali Redelonghi,19.01.1970";
	int pos2;
	// while loop
	int j = 0;
	while (!line2[j] == '\0') {
		if (line2[j] == ',') {
			pos2 = j;
			break;
		} else {
			j++;
		}
	}

	Mami *mami = malloc(sizeof(Mami));
	mami->name = malloc(sizeof(char) * (pos2 + 1));
	mami->new_date = malloc(sizeof(char) * 11);

	strncpy(mami->name, &line2[0], pos2);
	mami->name[strlen(mami->name)] = '\0';

	strncpy(day, &line2[pos2 + 1], 2);
	day[2] = '\0';
	strncpy(month, &line2[pos2 + 4], 2);
	month[2] = '\0';
	strncpy(year, &line2[pos2 + 7], 4);
	year[4] = '\0';
	sprintf(mami->new_date, "%s/%s/%s", day, month, year);

	printf("mami->name: %s\n", mami->name);
	printf("mami->new_date: %s\n", mami->new_date);
	free(mami->name);
	free(mami->new_date);
	free(mami);

	return 0;
 }

