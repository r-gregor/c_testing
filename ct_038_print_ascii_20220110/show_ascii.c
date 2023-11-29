#include <stdio.h>
#include <string.h>

void print_ascii_table();

int main(int argc, char** argv) {


	print_ascii_table();

	int n = 1024;
	float f = 3.1415926;
	char name[] = "Gregor Redelonghi";
	char sentence[strlen(name) + sizeof(int) + sizeof(float) + 1];
	sprintf(sentence, "Name: %s, num1: %d, numa2: %.3f", name, n, f);

	printf("Sentence: \"%s\"\n", sentence);
	printf("Length of sentence: %ld\n", strlen(sentence));


	return 0;
}

void print_ascii_table() {

	int cnt = 0;

	// printf("Num\tASCII\n");
	for (int i=33; i<127; i++) {
		cnt++;
		if (cnt % 5 == 0) {
			printf("%-4d%-6c\n", i, i);
		} else {
			printf("%-4d%-6c", i, i);
		}
	}
	printf("\n");
}

