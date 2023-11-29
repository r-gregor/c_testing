#include <stdio.h>
#include <string.h>

/*
 * "char** argv" is the same as "char* argv[]"
 */
int main(int argc, char** argv) {
	char* str1 = "Gregor Redelonghi";

	const int SECOND = 2;
	const int THIRD = 3;
	const int SEVENTH = 7;
	const int EIGHTH = 8;
	
	int position(int num) {
		return num - 1;
	}
	
	printf("Second char in string \"%s\" is \"%c\".\n", str1, *(str1 + position(SECOND)));
	printf("Third char in string \"%s\" is \"%c\".\n", str1, *(str1 + position(THIRD)));
	printf("Seventh char in string \"%s\" is \"%c\".\n", str1, *(str1 + position(SEVENTH)));
	printf("Eighth char in string \"%s\" is \"%c\".\n", str1, *(str1 + position(EIGHTH)));

	return 0;
}
