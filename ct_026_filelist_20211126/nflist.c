#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_CHARS_LINE 500

int nlines = 0;

void listFiles(const char* dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		return;
	}


	struct dirent* entity;
	entity = readdir(dir);
	while (entity != NULL) {
		if ( strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0 ) {
			if ( entity->d_type == DT_REG) {
			nlines++;
				printf("%-8d %s/%s\n", nlines, dirname, entity->d_name);
			}
		}
		entity = readdir(dir);
	}

	closedir(dir);
}

int main(int argc, char* argv[]) {

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

	return 0;
}

