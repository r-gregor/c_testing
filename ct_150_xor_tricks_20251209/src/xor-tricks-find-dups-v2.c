/* filenema: xor-tricks-find-dups.c
 * v1: 20251209 en
 * v2: 20251209 en
 * last: 20251209
 */
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	srand(time(0));                    // v2

	int dup = rand() % 100 + 1;        // v2
	for (int i = 1; i <= 100; ++i) {
		if (i == dup) {
			printf("%d\n", i);
		}
		printf("%d\n", i);
	}

	return 0;
}

