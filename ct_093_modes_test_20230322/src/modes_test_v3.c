/* v3
 * checks if value for -m is ON or OFF (ON must be next argument to -m!!)
 * regardless of the position inside of arguments list
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool mode = false;

int main(int argc, char **argv) {

	if (argc > 1) {
		for (int i=0; i < argc; i++) {
			if (strcmp(argv[i], "-m") == 0 && (argv[i + 1])) {
				if (strcmp(argv[i + 1], "ON") == 0) {
					mode = true;
					break;
				}
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

