#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_READ_LEN 256
#define STR_LEN 8

int main() {

	char buff[MAX_READ_LEN];
	printf("Lines read:\n");
	while((fscanf(stdin, "%s", buff)) == 1) {
		int buff_len = strlen(buff) + 1;
		printf("%s\n", buff);
		int last_eight_start = buff_len - (STR_LEN + 1);
		char last_eight[STR_LEN];
		strncpy(last_eight, &buff[last_eight_start], STR_LEN);
		last_eight[STR_LEN] = '\0';
		printf("Last 8 chars: '%s'\n", last_eight);
		
		for (size_t j=0; j < strlen(last_eight); j++) {
			if (isdigit((int) last_eight[j])) {
				printf("%c", last_eight[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

