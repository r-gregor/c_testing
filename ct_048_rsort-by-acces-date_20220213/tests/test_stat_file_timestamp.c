#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "==>\tUsage: \t%s <filename>\n", argv[0]);
		exit(1);
	}

	char *file_name = argv[1];
	struct stat finfo;
	char tmstmp[11];

	if (stat(file_name, &finfo) == -1) {
		perror("==>\tstat error");
		exit(2);
	}

	int yr = gmtime(&finfo.st_ctime)->tm_year + 1900;
	int mnt = gmtime(&finfo.st_ctime)->tm_mon;
	int dy = gmtime(&finfo.st_ctime)->tm_mday;
	sprintf(tmstmp, "%d-%.02d-%.02d", yr, mnt, dy);
	printf("%s %s\n", tmstmp, file_name);

	return 0;
}

