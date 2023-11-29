#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

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

void get_long_date(char *, char *);
void putFnameIntoArray(DIR *);
int sort_date(const void*, const void *);
FileName *fname_allocate(size_t);
char *string_allocate(size_t);
void release_ptr(void *);

/**
 * Main
 */
int main(int argc, char ** argv) {

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

	return(0);
} // end Main

void make_long_date(char *file_name, char *tmstmp) {
	struct stat finfo;
	if (stat(file_name, &finfo) == -1) {
		perror("==>\tstat error");
		exit(2);
	}

	int yr = gmtime(&finfo.st_ctime)->tm_year + 1900;
	int mnt = gmtime(&finfo.st_ctime)->tm_mon;
	int dy = gmtime(&finfo.st_ctime)->tm_mday;
	sprintf(tmstmp, "%d-%.02d-%.02d", yr, mnt, dy);

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
				filenames[fcount]            = fname_allocate(sizeof(FileName));
				filenames[fcount]->fname     = string_allocate(sizeof(char) * (strlen(dirent->d_name) + 1));
				filenames[fcount]->long_date = string_allocate(sizeof(char) * (LONG_DATE + 1));
				strcpy(filenames[fcount]->fname, dirent->d_name);
				char *path = realpath(dirent->d_name, NULL);
				printf("path: %s\n", path);
				make_long_date(path, filenames[fcount]->long_date);
				release_ptr(path);

				fcount++;
			}
		}
		closedir(dir);
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

