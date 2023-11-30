#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

void crta(int n) {
	for (int i=0; i<n; i++) {
		printf("-");
	}
	printf("\n");
}

void listFiles(const char* dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		return;
	}


	printf("%-40s%-20s%-20s\n", "Filename", "Size [b]", "Nr. lines");
	crta(69);

	struct dirent* entity;
	entity = readdir(dir);
	while (entity != NULL) {
		if ( strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0 ) {
			// char path[strlen(entity->d_name)];
			char path[500] = { 0 };
			if ( entity->d_type == DT_REG) {
				sprintf(path, "%s/%s", dirname, entity->d_name);
				struct stat finfo;

				if (stat(path, &finfo) == -1) {
					perror("==>\tstat error");
					exit(2);
				}

				off_t file_size = finfo.st_size;
				char *buffer = malloc(sizeof(char) * file_size + 100);

				FILE *fp = fopen(path, "r");

				if (!fp)  {
					fprintf(stderr, "Couldn't open file ");
					perror(NULL);
					exit(1);
				}

				if ((fread(buffer, 1, file_size, fp)) != file_size) {
					fprintf(stderr, "fread() failed");
					exit(EXIT_FAILURE);
				}

				fclose(fp);

				int lines_num = 0;
				for (int i=0; i<file_size; i++) {
					if (buffer[i] == '\n') {
						lines_num++;
					}
				}
				printf("%-40s%-20ld%-20d\n", entity->d_name, file_size, lines_num);
			}
		}
		entity = readdir(dir);
	}
	closedir(dir);
}


/* main */
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


