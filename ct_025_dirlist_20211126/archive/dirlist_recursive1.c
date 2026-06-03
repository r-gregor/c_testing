#include <stdio.h>
#include <string.h>
#include <dirent.h>

/*
 * downloaded from: https://code-vault.net/lesson/18ec1942c2da46840693efe9b526daa4
 * source: https://www.youtube.com/watch?v=j9yL30R6npk
 */


void listFiles(const char* dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		return;
	}

	struct dirent* entity;
	entity = readdir(dir);
	while (entity != NULL) {
		// printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);
		if ( strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0 ) {
			if ( entity->d_type == DT_DIR ) {
				printf("%s/%s/\n", dirname, entity->d_name);
			} else {
				printf("%s/%s\n", dirname, entity->d_name);
			}
		}
		if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
			char path[100] = { 0 };
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);
			if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
				listFiles(path);
			}
		}
		entity = readdir(dir);
	}

	closedir(dir);
}

int main(int argc, char* argv[]) {
	listFiles(".");
	return 0;
}


