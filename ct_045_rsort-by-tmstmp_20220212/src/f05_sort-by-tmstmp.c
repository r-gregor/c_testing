#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 25

typedef struct {
	char *date;
	char *fname;
	char *long_date;
} FileName;

FileName **filenames;

int *fcount;
int *numfr;

void make_tmstmp(char *, char *);
void putFnameIntoArray(DIR *);

/*
int comparator(const void* a, const void* b) {
    FileName *f_name1 = (FileName *)a;
    FileName *f_name2 = (FileName *)b;
    return (f_name1->date - f_name2->date);
}
*/

int main(int argc, char ** argv) {

	fcount = malloc(sizeof(int));
	numfr = malloc(sizeof(int));
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

	for (int i = 0; i < (*fcount); i++) {
		printf("%-11s %s\n", filenames[i]->long_date, filenames[i]->fname);
	}

	free(filenames);

	// test
	// printf("fcount: %d\n", *fcount);

	return(0);
}

void make_tmstmp(char *string, char *tmstmp) {

    
	// int substr_start = strlen(string)  - 12;
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
				FileName *f_name = malloc(sizeof(FileName));
				f_name->fname = malloc(sizeof(char) * 255);
				f_name->date = malloc(sizeof(char) * 9);
				f_name->long_date = malloc(sizeof(char) * 11);

				char *ndate = malloc(sizeof(char) * 9);
				char *tms = malloc(sizeof(char) * 11);

				sprintf(ndate, "%d", 20220126 + (*fcount));
				make_tmstmp(ndate, tms);
				
				// test
				// printf("tms: %s\n", tms);

				filenames[(*fcount)] = f_name;
				f_name->fname = dir->d_name;
				f_name->date = ndate;
				f_name->long_date = tms;

				(*fcount)++;
			}
		}
		closedir(d);
	}
}

