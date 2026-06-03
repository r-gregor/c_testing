#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void print_file_info();
void print_file_info2();

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "==>\tUsage: \t%s <filename>\n", argv[0]);
		exit(1);
	}

	char *file_name = argv[1];

	/* TEST
	printf("File name: %s\n", file_name);
	*/

	/* ======================= first part: filesize =========================== */ 
	/* stat struct initialization */
	struct stat finfo;

	/* if stat not possible error
	 * else: store size in st_size
	 * element of stst struct
	 */
	if (stat(file_name, &finfo) == -1) {
		perror("==>\tstat error");
		exit(2);
	}

	off_t file_size = finfo.st_size;



	/* ====================== second part: linescount ========================= */
	
	char buffer[file_size];

	FILE *fp = fopen(file_name, "r");

	if (!fp)  {
		fprintf(stderr, "Couldn't open file ");
		perror(NULL);
		exit(1);
	}

	fread(&buffer, 1, file_size, fp);

	fclose(fp);

	int lines_num = 0;
	for (int i=0; i<file_size; i++) {
		if (buffer[i] == '\n') {
			lines_num++;
		}
	}



	/* ====================== third part: printout  =========================== */

	/* printout-1 */
	print_file_info(file_name, file_size, lines_num);


	/*
	// printout-2 
	print_file_info2(file_name, file_size, lines_num);
	*/


	return 0;
}

void print_file_info2(char *fname, int size, int lines) {
	printf("%-20s%-20s%-20s\n", "Filename", "Size", "Nr. lines");
	printf("-----------------------------------------------------\n");
	printf("%-20s%-20d%-20d\n", fname, size, lines);
}

void print_file_info(char *fname, long size, int lines) {
	printf("%-10s%s\n", "Filename:", fname);
	printf("%-10s%ld bytes\n", "Size:", size);
	printf("%-10s%d\n", "Lines:", lines);
	printf("---\n");
}

