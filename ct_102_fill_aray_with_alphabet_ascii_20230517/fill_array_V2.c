#include <stdio.h>
#include <string.h>
#define NUM_CHARS_IN_APLHAB 26

/**
 * V2
 */

void show_alphabcet(char *array);
void show_alphabcet_2_lines(char *array);

/** main */
int main(int argc, char **argv) {

	char abc[NUM_CHARS_IN_APLHAB * 2];

	for (int i=0; i < NUM_CHARS_IN_APLHAB; i++) {
		abc[i] = 'a' + i;
		abc[i + NUM_CHARS_IN_APLHAB] = 'A' + i;
	}

	show_alphabcet(abc);
	printf("---\n");
	show_alphabcet_2_lines(abc);

	return 0;
} // end main

/**
* show lowercase and uppercase alphabcet in separate lines
*/
void show_alphabcet_2_lines(char *array) {
	for (int i = 0; i < (NUM_CHARS_IN_APLHAB * 2) - 1; i++) {
		if ((i + 1) % 26 == 0) {
			printf("%c\n", array[i]);
		} else {
			printf("%c, ", array[i]);
		}
	}
	printf("%c\n", array[(NUM_CHARS_IN_APLHAB * 2) - 1]);
}

/**
* show lowercase and uppercase alphabcet on sigle line
*/
void show_alphabcet(char *array) {
	for (int i = 0; i < (NUM_CHARS_IN_APLHAB * 2) - 1; i++) {
		printf("%c, ", array[i]);
	}
	printf("%c\n", array[(NUM_CHARS_IN_APLHAB * 2) - 1]);
}

