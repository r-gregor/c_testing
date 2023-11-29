#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_READ_LEN 256
#define STR_LEN 8

int main() {

	char buff[MAX_READ_LEN];
	// while((fscanf(stdin, "%s", buff)) != "\n") {
	printf("Lines read:\n");
	while((fscanf(stdin, "%s", buff)) == 1) {
		printf("%s\n", buff);
	}

	return 0;
}

