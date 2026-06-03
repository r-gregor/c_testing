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
 * started off from dirlist_nonrecursive4.c
 */

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
				printf("%s/%s\n", dirname, entity->d_name);
			}
		}

		if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
			char path[100] = { 0 };
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);
			strcat(path, "/");
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


