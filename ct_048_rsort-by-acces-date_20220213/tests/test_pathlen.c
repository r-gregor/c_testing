#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN1 20
#define MAX_LEN2 6

void linelen(char *);

int main(int argc, char **argv) {
void printchars(char *);
void printall(char *, size_t);
void printsize(int);

	char as[10] = "AAAAAAAAAA";
	char *testline = malloc(sizeof(char) * MAX_LEN1);
	strcpy(testline, as);
	linelen(testline);
	printsize(MAX_LEN1);
	printall(testline, MAX_LEN1);

	char bs[10] = "BBBBBBBBBB";
	char *testline2 = malloc(sizeof(char) * MAX_LEN2);
	strncpy(testline2, bs, 4);
	linelen(testline2);
	printsize(MAX_LEN2);
	printall(testline2, MAX_LEN2);

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

void printsize(int size) {
	printf("Size of line: %d\n", size);
}

