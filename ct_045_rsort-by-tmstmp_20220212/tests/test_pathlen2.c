#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void linelen(char *);

int main(int argc, char **argv) {
void printchars(char *);
void printall(char *, size_t);
void printsize(size_t);

	char as[10] = "AAAAAAAAAA";
	char *testline = malloc(sizeof(as) + 1);
	strcpy(testline, as);
	linelen(testline);
	printsize(sizeof(as) + 1);
	printall(testline, sizeof(as) + 1);

	char bs[10] = "BBBBBBBBBB";
	char *testline2 = malloc(sizeof(bs) + 1);
	strncpy(testline2, bs, 4);
	linelen(testline2);
	printsize(sizeof(bs) + 1);
	printall(testline2, sizeof(bs) + 1);

	free(testline);
	free(testline2);

	return 0;
}

void linelen(char *testline) {
	printf("Length of \"%s\": %ld\n", testline, strlen(testline));
}

void printchars(char *testline) {
	int i = 0;
	while(testline[i] != '\0') {
		printf("'%c', ", testline[i]);
	i++;
	}
	printf("\n");
}

void printall(char *line, size_t size) {
	for (size_t j = 0; j < size; j++) {
		printf("'%c', ", line[j]);
	}
	printf("\n");
}

void printsize(size_t size) {
	printf("Size of line: %ld\n", size);
}

