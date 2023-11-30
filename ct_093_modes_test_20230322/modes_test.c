/* v4
 * checks if value for -m is ON or OFF (ON must be next argument to -m!!)
 * and if -h is set to display usage (only if -m is OFF)
 * regardless of the position inside of arguments list
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool mode = false;
bool usage = false;

void msg();

int main(int argc, char **argv) {

	if (argc > 1) {
		for (int i=0; i < argc; i++) {
			if (strcmp(argv[i], "-m") == 0 && (argv[i + 1])) {
				if (strcmp(argv[i + 1], "ON") == 0) {
					mode = true;
					break;
				}
			}
			if (strcmp(argv[i], "-h") == 0) {
				usage = true;
			}
		}
	}

	if (mode == true) {
		usage = false;
		printf("The mode is ON!\n");
	} else if (usage == true ) {
		msg();
	} else {
		printf("The mode is off. (schmrc, shhmrc, ...)\n");
	}


	return 0;
}

void msg() {
	printf("Usage:\n");
	printf("\tPrints message if ON or OFF based on values of arguments to command:\n");
	printf("\tIf any two consecutive arguments are \"-m ON\" it displays ON message, else\n");
	printf("\tit displays OFF mesage.\n");
	printf("\n");
}

