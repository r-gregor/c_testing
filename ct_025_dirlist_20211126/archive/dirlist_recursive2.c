#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_OUTPUT_LINES 20

/*
 * downloaded from: https://code-vault.net/lesson/18ec1942c2da46840693efe9b526daa4
 * source: https://www.youtube.com/watch?v=j9yL30R6npk
 */

/*
 * v2: added option to pass any directory as an argument to main
 */

int nlines = 0;

void listFiles(const char* dirname, int *nlines) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		return;
	}

/*
 * 	if ( *nlines >= 20 ) {
 * 		exit(0);
 * 	}
 */

	struct dirent* entity;
	entity = readdir(dir);
	while (entity != NULL) {
		// printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);
		if ( strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0 ) {
			(*nlines)++;
			if ( entity->d_type == DT_DIR ) {
				printf("%d %s/%s/\n", *nlines, dirname, entity->d_name);
			} else {
				printf("%d %s/%s\n", *nlines, dirname, entity->d_name);
			}
		}
		if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
			char path[255] = { 0 };
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);
			if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
				listFiles(path, nlines);
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
	}


	listFiles(path, &nlines);
	return 0;
}


