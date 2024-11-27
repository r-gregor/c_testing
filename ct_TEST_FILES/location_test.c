#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	char fpath[4069];
	printf("Filename without a path: %s\n", argv[0]);

	realpath(argv[0], fpath);
	printf("FULL path: %s\n", fpath);





	return 0;
}
