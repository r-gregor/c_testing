/*
 * filename: rsort-by-accdate-c.c
 * 20220912 v5 en: -  gmtime() --> month +1 (range from 0 to 11!)
 * 20240819 v5 en: -  perror --> strerror
 * 20251202 v6 en: - add ERROR if no directory found
 *                 - move everything in main into main driver function
 */

#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 200
#define SHORT_DATE 8
#define LONG_DATE 10


typedef struct filename {
	char *fname;
	char *long_date;
} FileName;

FileName **filenames;
int fcount;
int numfr;
char curr_path[4096];
char *line;
char *fullpath;

void get_long_date(char *, char *);
void putFnameIntoArray(DIR *);
int sort_date(const void*, const void *);
FileName *fname_allocate(size_t);
char *string_allocate(size_t);
void release_ptr(void *);
void make_long_date(char *file_name, char *tmstmp);
void rsort_by_accdate(int argc, char **argv);

/*
 * Main
 */
int main(int argc, char ** argv) {
	rsort_by_accdate(argc, argv);

	return 0;
} // end Main

void make_long_date(char *file_name, char *tmstmp) {
	struct stat finfo;
	if (stat(file_name, &finfo) == -1) {
		// perror("==>\tstat error");
		printf("%s ==>\tstat error: %s\n", file_name, strerror(errno));
		exit(2);
	}

	int yr = gmtime(&finfo.st_ctime)->tm_year + 1900;
	int mnt = gmtime(&finfo.st_ctime)->tm_mon + 1;   // month, range 0 to 11 -->+1
	int dy = gmtime(&finfo.st_ctime)->tm_mday;

	sprintf(tmstmp, "%d-%.02d-%.02d", yr, mnt, dy);

}

void putFnameIntoArray(DIR *dir) {
	struct dirent *dirent;
	if (!dir) {
		printf( "[ERROR] no such directory\n\n");
		return;
	}

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
			// test
			//printf("fname:  %s\n", filenames[fcount]->fname);
			//printf("d_name: %s\n", dirent->d_name);

			fullpath = realpath(curr_path, NULL);
			line = malloc(sizeof(fullpath) + sizeof(dirent->d_name) + sizeof(char) * 3);
			sprintf(line, "%s/%s", fullpath, dirent->d_name);
			release_ptr(fullpath);
			if ( dirent->d_type == DT_DIR ) {
				strcat(line, "/");
			}

			make_long_date(line, filenames[fcount]->long_date);
			free(line);
			fcount++;
		}
	}
	if ( !(fcount > 0)) {
		printf("[ERROR] no files found\n\n");
		return;
	}
}

int sort_date(const void* a, const void *b) {
	FileName *f1 = *(FileName **)a;
	FileName *f2 = *(FileName **)b;
	return strcmp(f2->long_date, f1->long_date);
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


void rsort_by_accdate(int argc, char **argv) {
	fcount = 0;
	numfr = 1;
	filenames = malloc((sizeof(FileName *)) * FCOUNT_STEP);
	DIR *dir;

	if (argc == 2) {
		strcpy(curr_path, argv[1]);
	} else {
		strcpy(curr_path, DEFAULT_LOCATION);
	}

	dir = opendir(curr_path);
	putFnameIntoArray(dir);
	closedir(dir);
	
	/* qsort ... */
	qsort(filenames, fcount, sizeof(FileName *), sort_date);

	for (int i = 0; i < fcount; i++) {
		fflush(stdout);
		printf("%4d  ", i + 1);
		printf("%-11s %s\n", filenames[i]->long_date, filenames[i]->fname);
	}

	for (int i = 0; i < fcount; i++) {
		release_ptr(filenames[i]->fname);
		release_ptr(filenames[i]->long_date);
		release_ptr(filenames[i]);
	}
	release_ptr(filenames);
}
