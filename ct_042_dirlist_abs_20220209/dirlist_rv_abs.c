#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CHARS_LINE 500
#define STEP 500

char **filenames;
int count;
char *line;
char *fullpath;

void addFilesToArray(const char*);
int compare_paths(const void *, const void *);
void release_ptr(void *);

/* main */
int main(int argc, char* argv[]) {

	filenames = malloc(sizeof(char *) * STEP);

	// input sanitization
	char path[255] = "";
	if (argc != 2) {
		strcpy(path, ".");
	} else {
		strcpy(path, argv[1]);
		if (path[strlen(path)-1] == '/') {
			path[strlen(path)-1] = '\0';
		}
	}

	addFilesToArray(path);

	qsort(filenames, count-1, sizeof(char *), compare_paths);

	for (int i=0; i<count-1; i++) {
		printf("%s\n", *(filenames + i));
		release_ptr(filenames[i]);
	}
	release_ptr(filenames);

	return 0;
} // end main


void addFilesToArray(const char* dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		return;
	}

	struct dirent* dp;
	while ((dp = readdir(dir)) != NULL) {
		if (count-1 >= STEP) {
			// realocate if necessary
			filenames = realloc(filenames, sizeof(char *) * ((count-1) + STEP));
		}

		if ( strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 ) {
			fullpath = realpath(dirname, NULL);
			line = malloc(sizeof(fullpath) + sizeof(dp->d_name) + sizeof(char) * 10);
			sprintf(line, "%s/%s", fullpath, dp->d_name);
			release_ptr(fullpath);
			if ( dp->d_type == DT_DIR ) {
				strcat(line, "/");
			}
			filenames[count++] = line;
			addFilesToArray(line);
		}
	}
	closedir(dir);
}

int compare_paths(const void *a, const void *b) {
	const char **pa,**pb;

	pa = (const char **)a;
	pb = (const char **)b;
	// return( strcmp(*pa,*pb) );
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

