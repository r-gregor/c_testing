/* 
 * v2
 * from:  "Scanf scansets, and reading a CSV file in C (fixed)"
 *        https://www.youtube.com/watch?v=k0BIzHDBkwE
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {

	char item[BUFSIZE];
	char delim;
	int item_count = 0;

	while (scanf("%[^,\n]%c", item, &delim) != EOF) {
		printf("%s, ", item);
		item_count++;
		if (delim == '\n') {
			printf(" (%d items)\n", item_count);
			item_count = 0; // reset to count items in next line
		}
	}

	return 0;
}

