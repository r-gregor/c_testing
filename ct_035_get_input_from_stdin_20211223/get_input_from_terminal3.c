#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_READ_LEN 256

int main() {

	char buff[MAX_READ_LEN];

	size_t buff_len = read(STDIN_FILENO, buff, MAX_READ_LEN);
	printf("String Length: %ld\n", buff_len);
	buff[buff_len] = '\0';
	printf("%s", buff);

	int last_eight_start = buff_len - 9;
	char last_eight[8];
	strncpy(last_eight, &buff[last_eight_start], 8);
	last_eight[8] = '\0';

	printf("Last 8 chars: '%s'\n", last_eight);


	return 0;
}

/*
 * OUTPUT:
 * $> echo "HHHHHHHHHHHHHHHHHHHHH12345678" | ./bin/get_input_from_trminal3.exe
 * String Length: 30
 * HHHHHHHHHHHHHHHHHHHHH12345678
 * Last 8 chars: '12345678'
 */
