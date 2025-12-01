/* filename: rsort-by-tmstmp-absp_c.c
 * v1 20251201 en
 * based on:rsort-by-tmstmp_c.c
 * added abs path to fname to be used with fzf ...
 * last: 20251201
 */

#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 256
#define MAX_DIRNAME_LEN 256
#define SHORT_DATE 8
#define LONG_DATE 10

typedef struct abs_filename {
	char *fname;
	char *longdate;
	char *abs_path;
} AbsFileName;

AbsFileName **filenames;
int fcount;
int numfr;
char *newdate;
char abs_pathname[MAX_DIRNAME_LEN];

void make_tmstmp(char *, char *);
void putFnameIntoArray(DIR *);
int isNumber(char *);
int lastEightIsNumber(char *);
AbsFileName *fname_allocate(size_t);
char *string_allocate(size_t);
void release_ptr(void *);
int sort_longdate(const void* , const void *);

/**
 * Main
 */
int main(int argc, char ** argv) {

	newdate = malloc(sizeof(char) * (SHORT_DATE + 1));
	fcount = 0;
	numfr = 1;
	filenames = malloc((sizeof(AbsFileName *)) * FCOUNT_STEP);
	DIR *dir;


	if (argc == 2) {
		dir = opendir(argv[1]);
		strcpy(abs_pathname,argv[1]);

	} else {
		dir = opendir(DEFAULT_LOCATION);
		strcpy(abs_pathname,DEFAULT_LOCATION);
	}

	putFnameIntoArray(dir);

	/* qsort ... */
	qsort(filenames, fcount, sizeof(AbsFileName *), sort_longdate);

	for (int i = 0; i < fcount; i++) {
		fflush(stdout);
		printf("%4d  ", i + 1);
		printf("%-11s %s/%s\n", filenames[i]->longdate, filenames[i]->abs_path, filenames[i]->fname);
	}

	for (int i = 0; i < fcount; i++) {
		release_ptr(filenames[i]->fname);
		release_ptr(filenames[i]->longdate);
		release_ptr(filenames[i]->abs_path);
		release_ptr(filenames[i]);
	}

	release_ptr(filenames);
	release_ptr(newdate);

	return(0);
} // end Main

int sort_longdate(const void* a, const void *b) {
	AbsFileName *f1 = *(AbsFileName **)a;
	AbsFileName *f2 = *(AbsFileName **)b;
	return strcmp(f2->longdate, f1->longdate);
}

void make_tmstmp(char *tmstmp, char *string) {
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
				filenames = realloc(filenames, (sizeof(AbsFileName *)) * (FCOUNT_STEP * numfr));
			}

			if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) {
				if (lastEightIsNumber(dirent->d_name)) {
					filenames[fcount]            = fname_allocate(sizeof(AbsFileName));
					filenames[fcount]->fname     = string_allocate(sizeof(char) * (strlen(dirent->d_name) + 1));
					filenames[fcount]->longdate  = string_allocate(sizeof(char) * (LONG_DATE + 1));
					filenames[fcount]->abs_path  = string_allocate(sizeof(abs_pathname) + 1);
					strcpy(filenames[fcount]->fname, dirent->d_name);
					strcpy(filenames[fcount]->abs_path, realpath(abs_pathname, NULL));
					make_tmstmp(filenames[fcount]->longdate, newdate);
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
	char last_eight[SHORT_DATE + 1];
	strncpy(last_eight, &line[last_eight_start], SHORT_DATE);
	last_eight[SHORT_DATE] = '\0';

	if (isNumber(last_eight)) {
		strcpy(newdate, last_eight);
		return 1;
	}

	return 0;
} 

AbsFileName *fname_allocate(size_t size) {
	AbsFileName *fname_ptr;
	fname_ptr = malloc(size);
	if (fname_ptr == NULL) {
		fprintf(stderr, "Out of memory!");
		exit(EXIT_FAILURE);
	}

	return fname_ptr;
}

char *string_allocate(size_t size) {
	char *string;
	string = malloc(size);
	if (string == NULL) {
		fprintf(stderr, "Out of memory!");
		exit(EXIT_FAILURE);
	}

	return string;
}

void release_ptr(void *ptr) {
	if (ptr == NULL) {
		printf("Already free!");
		exit(EXIT_SUCCESS);
	}

	free(ptr);
	ptr = NULL;
}

