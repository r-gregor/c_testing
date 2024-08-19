#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>
#include <errno.h>

char curr_path[4096];
void printAccesDate(char *path);
void printAccesDateAbs(char *path);

/**
 * Main
 */
int main(int argc, char ** argv) {

	if (argc == 2) {
		strcpy(curr_path, argv[1]);
	} else {
		strcpy(curr_path, ".");
	}

	printAccesDateAbs(curr_path);
	
	printf("---\n");

	char paths_list[5][512];
	strcpy(paths_list[0], "bin");
	strcpy(paths_list[1], "Makefile");
	strcpy(paths_list[2], "realpath_test_v5.c");
	strcpy(paths_list[3], "test_comparisons.c");
	strcpy(paths_list[4], "test_sort_structs_by_hypen-delimited-date.c");

	char paths_list2[5][512];
	strcpy(paths_list2[0], "../src");
	strcpy(paths_list2[1], "../tests");
	strcpy(paths_list2[2], "../Makefile");
	strcpy(paths_list2[3], "../rsort-by-accdate_c.c");
	strcpy(paths_list2[4], "../rsort-by-accdate_c_v2.c");
 
	for (int i=0; i < 5; i++) {
		printAccesDate(paths_list[i]);
		// printAccesDateAbs(paths_list[i]);
	}

	printf("---\n");

	for (int i=0; i < 5; i++) {
		printAccesDate(paths_list2[i]);
		// printAccesDateAbs(paths_list2[i]);
	}

	return(0);
} // end Main


void printAccesDate(char *path) {
	char rpath[4096];
	realpath(path, rpath);

	struct stat finfo;
	if (stat(rpath, &finfo) == -1) {
		// perror("==>\tstat error");
		printf("%s ==>\tstat error: %s\n", path, strerror(errno));
		exit(2);
	}

	int yr = gmtime(&finfo.st_ctime)->tm_year + 1900;
	int mnt = gmtime(&finfo.st_ctime)->tm_mon + 1;   // month, range 0 to 11 -->+1
	int dy = gmtime(&finfo.st_ctime)->tm_mday;

	// sprintf(tmstmp, "%d-%.02d-%.02d", yr, mnt, dy);
	printf("%d-%.02d-%.02d ", yr, mnt, dy);
	printf("%s\n", path);

}


void printAccesDateAbs(char *path) {
	char rpath[4096];
	realpath(path, rpath);

	struct stat finfo;
	if (stat(rpath, &finfo) == -1) {
		// perror("==>\tstat error");
		printf("%s ==>\tstat error: %s\n", path, strerror(errno));
		exit(2);
	}

	int yr = gmtime(&finfo.st_ctime)->tm_year + 1900;
	int mnt = gmtime(&finfo.st_ctime)->tm_mon + 1;   // month, range 0 to 11 -->+1
	int dy = gmtime(&finfo.st_ctime)->tm_mday;

	// sprintf(tmstmp, "%d-%.02d-%.02d", yr, mnt, dy);
	printf("%d-%.02d-%.02d ", yr, mnt, dy);
	printf("%s\n", rpath);

}
