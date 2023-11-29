#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 200
#define MAX_LINE_CHARS 256
#define STR_LEN 8

typedef struct filename {
	char *fname;
	char *long_date;
} FileName;

FileName **filenames;

int fcount;
int numfr;
char *newdate;
char *tms;

void make_tmstmp(char *, char *);
void putFnameIntoArray(DIR *);
int isNumber(char *);
int lastEightIsNumber(char *);

int sort_long_date(const void* a, const void *b) {
	FileName *f1 = *(FileName **)a;
	FileName *f2 = *(FileName **)b;
	return strcmp(f2->long_date, f1->long_date);
}

int main(int argc, char ** argv) {

	newdate = malloc(sizeof(char) * 9);
	fcount = 0;
	numfr = 1;
	filenames = malloc((sizeof(FileName *)) * FCOUNT_STEP);
	DIR *dir;

	if (argc == 2) {
		dir = opendir(argv[1]);
	} else {
		dir = opendir(DEFAULT_LOCATION);
	}
	putFnameIntoArray(dir);
	
	/* qsort ... */
	qsort(filenames, fcount, sizeof(FileName *), sort_long_date);


	for (int i = 0; i < fcount; i++) {
		fflush(stdout);
		printf("%4d  ", i + 1);
		printf("%-11s %s\n", filenames[i]->long_date, filenames[i]->fname);
	}

	for (int i = 0; i < fcount; i++) {
		free(filenames[i]->fname);
		free(filenames[i]->long_date);
		free(filenames[i]);
		filenames[i] = NULL;
	}

	free(filenames);
	filenames=NULL;

	free(newdate);
	newdate = NULL;

	free(tms);
	tms = NULL;

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

void putFnameIntoArray(DIR *dir) {
	struct dirent *dirent;
	if (dir) {
		while ((dirent = readdir(dir)) != NULL) {
			
			if (fcount == (FCOUNT_STEP * numfr)) {
				numfr += 1;
				filenames = realloc(filenames, (sizeof(FileName *)) * (FCOUNT_STEP * numfr));
			}

			if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) {
				if (lastEightIsNumber(dirent->d_name)) {
					filenames[fcount] = malloc(sizeof(FileName));
					filenames[fcount]->fname = malloc(sizeof(char) * (strlen(dirent->d_name) + 1));
					filenames[fcount]->long_date = malloc(sizeof(char) * 11);
					tms = malloc(sizeof(char) * 11);
					strcpy(filenames[fcount]->fname, dirent->d_name);
					make_tmstmp(newdate, tms);
					filenames[fcount]->long_date = tms;
					fcount++;
				}
			}
		}
		closedir(dir);
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

	if (strlen(line) <= 12) {
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

	return 0;
} 
