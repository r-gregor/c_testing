#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CHARS_LINE 500

char **filenames;
int count;

char *line;
char *fullpath;

void listFiles(const char* dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		return;
	}

	struct dirent* dp;
	while ((dp = readdir(dir)) != NULL) {
		if ( strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 ) {
			fullpath = realpath(dirname, NULL);
			line = malloc(sizeof(fullpath) + sizeof(dp->d_name) + sizeof(char) * 10);
			sprintf(line, "%s/%s", fullpath, dp->d_name);
			if ( dp->d_type == DT_DIR ) {
				strcat(line, "/");
			}
			filenames[count++] = line;
			listFiles(line);
		}
	}
	closedir(dir);
}

int main(int argc, char* argv[]) {

	filenames = malloc(sizeof(char *) * 500);

	char path[255] = "";
	if (argc != 2) {
		strcpy(path, ".");
	} else {
		strcpy(path, argv[1]);
		if (path[strlen(path)-1] == '/') {
			path[strlen(path)-1] = '\0';
		}
	}

	listFiles(path);
	free(line);


	for (int i=0; i<count; i++) {
		printf("%s\n", *(filenames + i));
	}

	return 0;
}


