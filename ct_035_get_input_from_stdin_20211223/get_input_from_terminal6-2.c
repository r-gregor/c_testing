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
	while((fscanf(stdin, "%s", buff)) == 1) {
		char line[MAX_READ_LEN];
		sprintf(line, "%s", buff);
		int buff_len = strlen(buff) + 1;
		int last_eight_start = buff_len - (STR_LEN + 1);
		char last_eight[STR_LEN];
		strncpy(last_eight, &buff[last_eight_start], STR_LEN);
		last_eight[STR_LEN] = '\0';

		if (buff_len < 8) {
			continue;
		}

		if (isNumber(last_eight)) {
			printf("[%s] %s\n", last_eight, line);
			// printf("Last 8 chars: '%s'\n", last_eight);
		} else {
			continue;
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

