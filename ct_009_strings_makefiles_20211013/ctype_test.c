#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int NLINES = 36;

void crta(int n) {
	while(n != 0) {
		printf("-");
		n--;
	}
	printf("\n");
}

void ascii_char_codes(char *array) {
	printf("\n");
	// len1 = (sizeof(array) / sizeof(char)) - 1;
	size_t len1 = strlen(array);
	/* header */
	crta(NLINES);
	printf("Char ASCII   Char ASCII   Char ASCII\n");
	crta(NLINES);
	int cnt = 0;
	for (int i=0; i<len1; i++) {
		cnt++;
		char c2 = array[i];
		if (cnt % 3 == 0) {
			printf("%-5c%-8d\n", c2, c2);
		} else {
			printf("%-5c%-8d", c2, c2);
		}
	}
	printf("\n");
}

int main() {
	const char myname[] = "Gregor";
	printf("The length of string \"%s\" is: %ld.\n",  myname, strlen(myname));
	printf("The 'sizeof' of \"%s\" is: %ld.\n", myname, sizeof(myname));

	int len = (sizeof(myname) / sizeof(char)) - 1;

	for (int i=0; i < len; i++) {
		int c1 = (int) myname[i];
		if isupper(c1) {
			printf("Char %c (%d) is UpperCase.\n", c1, c1);
		} else {
			printf("Char %c (%d) is lowerCase.\n", c1, c1);
		}
	}

	char lcl[] = "abcdefghijklmnopqrstuvwxyz";
	char ucl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	ascii_char_codes((char*) lcl);
	ascii_char_codes((char*) ucl);

	return 0;
}