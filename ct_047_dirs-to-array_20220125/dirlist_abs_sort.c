#include <dirent.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define DEFAULT_LOCATION "."
#define FCOUNT_STEP 25

char *line;
char *fullpath;
const char *dirname;
void release_ptr(void *);

int compare_paths(const void *a, const void *b);

int main(int argc, char ** argv) {
	DIR *d;
	struct dirent *dir;
	int fcount = 0;
	int numfr = 1;
	char **filenames = malloc(sizeof(char *) * (FCOUNT_STEP * numfr));

	if (argc == 2) {
		dirname = argv[1];
	} else {
		dirname = DEFAULT_LOCATION;
	}


	d = opendir(dirname);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (fcount >= FCOUNT_STEP * numfr) {
				numfr += 1;
				filenames = realloc(filenames, sizeof(char *) * (FCOUNT_STEP * numfr));
			}

			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
				fullpath = realpath(dirname, NULL);
				line = malloc(sizeof(fullpath) + sizeof(dir->d_name) + sizeof(char) * 2);
				sprintf(line, "%s/%s", fullpath, dir->d_name);
				release_ptr(fullpath);
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
		release_ptr(filenames[i]);
	}
	release_ptr(filenames);

	return(0);
}

int compare_paths(const void *a, const void *b) {
    const char **pa,**pb;

    pa = (const char **)a;
    pb = (const char **)b;
    return( strcasecmp(*pa,*pb) );
}


void release_ptr(void *ptr) {
	if (ptr == NULL) {
		printf("Already free!");
		exit(EXIT_SUCCESS);
	}

	free(ptr);
	ptr = NULL;
}

