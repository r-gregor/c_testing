#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	char name[] = "GREGOR_REDELONGHI";

	char *pos = name;
	while(*pos != '\0') {
		printf("%c ", *pos++);
	}
	printf("\n");


	return 0;
}
