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

	return 0;
}

