/* v2
 * checks all arguments for "s" or "S"
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool mode = false;

int main(int argc, char **argv) {

	if (argc > 1) {
		for (int i=0; i < argc; i++) {
			if (strcmp(argv[i], "s") == 0 || strcmp(argv[i], "S") == 0) {
				mode = true;
				break;
			}
		}
	}

	if (mode) {
		printf("The mode is ON!\n");
	} else {
		printf("The mode is off. (schmrc, shhmrc, ...)\n");
	}


	return 0;
}

