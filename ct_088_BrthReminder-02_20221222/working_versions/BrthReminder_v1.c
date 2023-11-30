#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * vi - ORIGINAL
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
	if (argc != 2) {
		fprintf(stderr, "Please supply a file path:\n%s <file path>\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *fp = fopen(argv[1], "r");
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
		printInfo(line);
	}
	free(line);
	fclose(fp);

	return 0;
} /* end main */

/**
 * function that returns the position of the delimiter in a string
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
 * function that extracts [name],[date] from string
 * and prints those separately
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

