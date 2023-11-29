#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BASE_CHUNG_LENGTH 16
#define MAX_READ_LEN 32

void read_num_chars_from_stdin(int);

int main() {

	printf("Reading first %d chars from stdin ...\n", MAX_READ_LEN);
	read_num_chars_from_stdin(MAX_READ_LEN);

	return 0;
}

void read_num_chars_from_stdin(int num_chars) {

	if (num_chars % BASE_CHUNG_LENGTH != 0) {
		printf("Number must be a multiple of %d\n", BASE_CHUNG_LENGTH);
		exit(1);
	}

	int ratio = MAX_READ_LEN / BASE_CHUNG_LENGTH;
	char buff[MAX_READ_LEN + 2];

	size_t bytes_read = read(STDIN_FILENO, buff, MAX_READ_LEN);
	buff[bytes_read] ='\0';

	printf("%s\n", buff);
	for (int i = 0; i < ratio; i++) {
		printf("0123456789ABCDEF");
	}
	printf("\n\n");
}

