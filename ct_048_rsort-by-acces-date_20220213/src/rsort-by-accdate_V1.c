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
#define MAX_LINE_CHARS 256
#define STR_LEN 8

typedef struct filename {
	char *fname;
	char *long_date;
} FileName;

FileName **filenames;

int fcount;
int numfr;
char *tmstmp;

void get_long_date(char *, char *);
void putFnameIntoArray(DIR *);

int sort_date(const void* a, const void *b) {
	FileName *f1 = *(FileName **)a;
	FileName *f2 = *(FileName **)b;
	return strcmp(f2->long_date, f1->long_date);
}

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
		free(filenames[i]);
		filenames[i] = NULL;
	}

	free(filenames);
	filenames=NULL;

	return(0);
}

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
				tmstmp = malloc(sizeof(char) * 11);
				filenames[fcount] = malloc(sizeof(FileName));
				filenames[fcount]->fname = malloc(sizeof(char) * (strlen(dirent->d_name) + 1));
				filenames[fcount]->long_date = malloc(sizeof(char) * 11);
				strcpy(filenames[fcount]->fname, dirent->d_name);
				make_long_date(dirent->d_name, tmstmp);
				strcpy(filenames[fcount]->long_date, tmstmp);
				fcount++;
			}
		}
		closedir(dir);
	}
}

