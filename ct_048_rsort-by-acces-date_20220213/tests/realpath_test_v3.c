#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 200
#define SHORT_DATE 8
#define LONG_DATE 10

/*
 * update 20220912:
 * gmtime() --> month +1 (range from 0 to 11!)
 */

typedef struct filename {
	char *fname;
	char *long_date;
} FileName;

FileName **filenames;
int fcount;
int numfr;

void get_long_date(char *, char *);
void displayRealPath(DIR *); // NEW
FileName *fname_allocate(size_t);
char *string_allocate(size_t);
void release_ptr(void *);
void make_long_date(char *file_name, char *tmstmp);

/**
 * Main
 */
int main(int argc, char ** argv) {

	fcount = 0;
	numfr = 1;
	filenames = malloc((sizeof(FileName *)) * FCOUNT_STEP);
	DIR *dir;

	if (argc == 2) {
		char curr_pth[1024];
		strcpy(curr_pth, argv[1]);
		dir = opendir(curr_pth);
	} else {
		dir = opendir(DEFAULT_LOCATION);
	}
	displayRealPath(dir);
	
	for (int i = 0; i < fcount; i++) {
		release_ptr(filenames[i]->fname);
		release_ptr(filenames[i]->long_date);
		release_ptr(filenames[i]);
	}
	release_ptr(filenames);

	return(0);
} // end Main

void displayRealPath(DIR *dir) {
	struct dirent *dirent;
	if (dir) {
		while ((dirent = readdir(dir)) != NULL) {
			if (fcount == (FCOUNT_STEP * numfr)) {
				numfr += 1;
				filenames = realloc(filenames, (sizeof(FileName *)) * (FCOUNT_STEP * numfr));
			}

			if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) {
				filenames[fcount]            = fname_allocate(sizeof(FileName));
				filenames[fcount]->fname     = string_allocate(sizeof(char) * (strlen(dirent->d_name) + 1));
				filenames[fcount]->long_date = string_allocate(sizeof(char) * (LONG_DATE + 1));
				strcpy(filenames[fcount]->fname, dirent->d_name);
				printf("filenames[%d]: %s\n", fcount, filenames[fcount]->fname);
				char *path = realpath(filenames[fcount]->fname, NULL);
				#if 1
				printf("path: %s\n", path);
				#endif
				fcount++;
			}
		}
		closedir(dir);
	}
}

FileName *fname_allocate(size_t size) {
	FileName *fname_ptr;
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

