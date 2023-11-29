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


char curr_path[4096];
/**
 * Main
 */
int main(int argc, char ** argv) {

	if (argc == 2) {
		strcpy(curr_path, argv[1]);
	} else {
		strcpy(curr_path, ".");
	}
	
	char rpath[4096];
	realpath(curr_path, rpath);
	printf("%s -- ", rpath);

	struct stat finfo;
	if (stat(rpath, &finfo) == -1) {
		perror("==>\tstat error");
		exit(2);
	}

	int yr = gmtime(&finfo.st_ctime)->tm_year + 1900;
	int mnt = gmtime(&finfo.st_ctime)->tm_mon + 1;   // month, range 0 to 11 -->+1
	int dy = gmtime(&finfo.st_ctime)->tm_mday;

	// sprintf(tmstmp, "%d-%.02d-%.02d", yr, mnt, dy);
	printf("%d-%.02d-%.02d\n", yr, mnt, dy);

	return(0);
} // end Main

