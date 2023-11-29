#include <stdio.h>
#include <string.h>

void printByChars(char *, size_t);

int main() {
	char string[256];
	printf("Enter string: \n");
	fgets(string, 256, stdin);
	printf("---\n");
	printf("String: %s", string);

	size_t length = strlen(string);

	printByChars(string, length);
	printf("String legth = %ld\n", length);

	// replacing trailin newline with '\0'
	string[length - 1] = '\0';
	printf("\n---\nAfter removing trailing newline:\n");
	printByChars(string, length);
	printf("New string legth = %ld\n", strlen(string));

	return 0;
}

void printByChars(char *string, size_t len) {
	for (int i=0; i<=len; i++) { // i <= length !!!
		if (string[i] == '\n')
			printf("string[%d] = \\n \n", i);
		else if (string[i] == ' ')
			printf("string[%d] = space\n", i);
		else if (string[i] == '\0')
			printf("string[%d] = \\0 \n", i);
		else
			printf("string[%d] = %c\n", i, string[i]);
	}
}

