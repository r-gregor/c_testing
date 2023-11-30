#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	char *line = "Gregor Redelonghi 22 02 1968";
	for (int i = 0; i < strlen(line); i++) {
		printf("character: %-2c --> code-num: %-4d\n", line[i], line[i]);
	}


	return 0;
}

