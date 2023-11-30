#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


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
	printf("The size of %s: %ld bytes\n", file_name, file_size);
	printf("---\n");




	return 0;
}

