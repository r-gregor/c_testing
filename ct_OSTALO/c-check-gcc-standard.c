#include <stdio.h>

int main() {
	char *STD;
	switch(__STDC_VERSION__) {
		case 201112L:
			STD = "C11";
			break;

		case 201710L:
			STD = "C17";
			break;

		case 199901L:
			STD = "C99";
			break;

		case 199409L:
			STD = "C89/C90";
			break;

		default:
			printf("[ERROR] Unknown std\n");
			return -1;
	}

	printf("gcc standard: %s (%ld)\n", STD, __STDC_VERSION__);
	return 0;
}

