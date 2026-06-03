/* v1
 * checks if single argument is "s" or "S"
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool mode = false;

int main(int argc, char **argv) {

	if (argc == 2) {
		if (strcmp(argv[1], "s") == 0 || strcmp(argv[1], "S") == 0) {
			mode = true;
		}
	}

	if (mode) {
		printf("The mode is ON!\n");
	} else {
		printf("The mode is off. (schmrc, shhmrc, ...)\n");
	}


	return 0;
}

