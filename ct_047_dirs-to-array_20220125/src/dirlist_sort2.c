#include <stdio.h> 
#include <dirent.h>  
#include <string.h> 
#include <stdlib.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 25

char *line;

int compare_paths(const void *a, const void *b) {
    const char **pa,**pb;

    pa = (const char **)a;
    pb = (const char **)b;
    return( strcasecmp(*pa,*pb) );
}

int main(int argc, char ** argv) {
	DIR *d;
	struct dirent *dir;
	int fcount = 0;
	int numfr = 1;
	char **filenames = malloc(sizeof(char *) * (FCOUNT_STEP * numfr));

	if (argc == 2) {
		d = opendir(argv[1]);
	} else {
		d = opendir(DEFAULT_LOCATION);
	}

	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (fcount >= FCOUNT_STEP * numfr) {
				numfr += 1;
				filenames = realloc(filenames, sizeof(char *) * (FCOUNT_STEP * numfr));
			}

			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
				line = malloc(sizeof(dir->d_name) + 1);
				strcpy(line, dir->d_name);
				if ( dir->d_type == DT_DIR ) {
					strcat(line, "/");
				}
				filenames[fcount] = line;
				fcount++;
			}
		}
		closedir(d);
	}

	qsort(filenames, fcount, sizeof(char *), compare_paths);

	for (int i = 0; i < fcount; i++) {
		printf("%s\n", filenames[i]);
		free(filenames[i]);
	}
	free(filenames);

	return(0);
}

