#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char **argv) {
	
	DIR *directory;
	struct dirent *entry;

	// directory = opendir("/home/gregor.redelonghi/");
	directory = opendir("/c/Users/gregor.redelonghi/Downloads");

	if (directory == NULL) {
		printf("Error opening directory.\n");
		return 1;
	}

	while ((entry = readdir(directory)) != NULL) {
		if (entry->d_type == DT_REG) {
			printf("File: %s\n", entry->d_name);
		} else if (entry->d_type == DT_DIR) {
			printf(" Dir: %s/\n", entry->d_name);
		}
	}

	if (closedir(directory) == -1) {
		printf("Error closing directory!\n");
		return 1;
	}


	return 0;
}

