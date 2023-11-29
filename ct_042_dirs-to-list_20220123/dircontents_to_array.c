#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define DEFAULT_LOCATION "."

int main(int argc, char ** argv) {
	DIR *d;
	struct dirent *dir;
	char *filenames[100];
	int fcount = 0;

	if (argc == 2) {
		d = opendir(argv[1]);
	} else {
		d = opendir(DEFAULT_LOCATION);
	}

	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
				filenames[fcount] = malloc(strlen(dir->d_name)+1);
				strcpy(filenames[fcount], dir->d_name);
				fcount++;
			}
		}
		closedir(d);
	}

	for (int i = 0; i < fcount; i++) {
		printf("%s\n", filenames[i]);
		free(filenames[i]);
	}

	return(0);
}

