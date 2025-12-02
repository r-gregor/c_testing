#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 25
#define MAX_LINE_CHARS 1000
#define STR_LEN 8

typedef struct filename {
	char date[9];
	char *fname;
	char *long_date;
} FileName;

FileName **filenames;

int *fcount;
int *numfr;
char *newdate;
char *tms;

void make_tmstmp(char *, char *);
void putFnameIntoArray(DIR *);
int isNumber(char *);
int lastEightIsNumber(char *);

int sort_date(const void* a, const void *b) {
	FileName *f1 = *(FileName **)a;
	FileName *f2 = *(FileName **)b;
	return strcmp(f2->date, f1->date);
}

int main(int argc, char ** argv) {

	fcount = malloc(sizeof(int));
	numfr = malloc(sizeof(int));
	newdate = malloc(sizeof(char) * 9);

	*fcount = 0;
	*numfr = 1;

	filenames = malloc(sizeof(FileName *) * (FCOUNT_STEP * (*numfr)));

	DIR *d;

	if (argc == 2) {
		d = opendir(argv[1]);
	} else {
		d = opendir(DEFAULT_LOCATION);
	}
	putFnameIntoArray(d);
	
	/* qsort ... */
	qsort(filenames, *fcount, sizeof(FileName *), sort_date);


	for (int i = 0; i < (*fcount); i++) {
		fflush(stdout);
		printf("%-11s %s\n", filenames[i]->long_date, filenames[i]->fname);
	}

	for (int i = 0; i < (*fcount); i++) {
		free(filenames[i]);
	}

	free(filenames); 

	free(fcount);
	free(numfr);
	free(newdate);
	free(tms);

	return(0);
}

void make_tmstmp(char *string, char *tmstmp) {
    
	int substr_start = strlen(string) - 8;
	char year[5];
	char month[3];
	char day[3];

	strncpy(year, &string[substr_start], 4);
	year[4] = '\0';

	strncpy(month, &string[substr_start + 4], 2);
	month[2] = '\0';

	strncpy(day, &string[substr_start + 6], 2);
	day[2] = '\0';

	sprintf(tmstmp, "%s-%s-%s", year, month, day);
}

void putFnameIntoArray(DIR *d) {

	struct dirent *dir;
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if ((*fcount) >= FCOUNT_STEP * (*numfr)) {

				(*numfr) += 1;
				filenames = realloc(filenames, sizeof(FileName *) * (FCOUNT_STEP * (*numfr)));
			}

			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
				if (lastEightIsNumber(dir->d_name)) {
					filenames[(*fcount)] = malloc(sizeof(FileName));
					filenames[(*fcount)]->fname = malloc(sizeof(char) * MAX_LINE_CHARS);
					filenames[(*fcount)]->long_date = malloc(sizeof(char) * 11);
					tms = malloc(sizeof(char) * 11);

					filenames[(*fcount)]->fname = dir->d_name;
					strncpy(filenames[(*fcount)]->date, newdate, 8);

					make_tmstmp(filenames[(*fcount)]->date, tms);
					filenames[(*fcount)]->long_date = tms;

					(*fcount)++;
				}
			}
		}
		closedir(d);
	}
}

int isNumber(char *s) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit((int) s[i]) == 0) {
			return 0;
		}
	}
	return 1;
}

int lastEightIsNumber(char *line) {

	if (strlen(line) <= 11) {
		return 0;
	}

	int last_eight_start = strlen(line) - 12;
	char last_eight[STR_LEN + 1];
	strncpy(last_eight, &line[last_eight_start], STR_LEN);
	last_eight[STR_LEN] = '\0';

	if (isNumber(last_eight)) {
		strcpy(newdate, last_eight);
		return 1;
	}

	strcpy(newdate, "19680222");
	return 0;
} 
