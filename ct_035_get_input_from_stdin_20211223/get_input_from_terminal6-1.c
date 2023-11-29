#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_READ_LEN 256
#define STR_LEN 8

int isNumber(char *);

int main() {

	char buff[MAX_READ_LEN];
	printf("Lines read:\n");
	while((fscanf(stdin, "%s", buff)) == 1) {
		printf("%s\n", buff);
		int buff_len = strlen(buff) + 1;
		int last_eight_start = buff_len - (STR_LEN + 1);
		char last_eight[STR_LEN];
		strncpy(last_eight, &buff[last_eight_start], STR_LEN);
		last_eight[STR_LEN] = '\0';
		
		if (isNumber(last_eight)) {
			printf("Last 8 chars: '%s'\n", last_eight);
			printf("\n");
		} else {
			printf("Last 8 chars are NOT digits!\n");
			printf("\n");
		}
	}
	return 0;
}

int isNumber(char *s) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit((int) s[i]) == 0) {
			return 0;
		}
	}
	return 1;
}

