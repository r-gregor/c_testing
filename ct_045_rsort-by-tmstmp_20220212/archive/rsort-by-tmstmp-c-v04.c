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

/*
int comparator(const void* a, const void* b) {
    FileName *f_name1 = (FileName *)a;
    FileName *f_name2 = (FileName *)b;
    return (f_name1->date - f_name2->date);
}
*/

int main(int argc, char ** argv) {
	DIR *d;
	struct dirent *dir;
	int fcount = 0;
	int numfr = 1;

	FileName **filenames = malloc(sizeof(FileName *) * (FCOUNT_STEP * numfr));

	if (argc == 2) {
		d = opendir(argv[1]);
	} else {
		d = opendir(DEFAULT_LOCATION);
	}

	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (fcount >= FCOUNT_STEP * numfr) {

				numfr += 1;
				filenames = realloc(filenames, sizeof(FileName *) * (FCOUNT_STEP * numfr));
			}

			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
				FileName *f_name = malloc(sizeof(FileName));
				f_name->fname = malloc(sizeof(char) * 255);
				f_name->date = malloc(sizeof(char) * 9);
				char *ndate = malloc(sizeof(char) * 9);
				sprintf(ndate, "%d", 20220126 + fcount);
				filenames[fcount] = f_name;
				f_name->fname = dir->d_name;
				f_name->date = ndate;
				fcount++;
			}
		}
		closedir(d);
	}

	for (int i = 0; i < fcount; i++) {
		printf("[%s] %s\n", filenames[i]->date, filenames[i]->fname);
	}

	free(filenames);

	return(0);
}

