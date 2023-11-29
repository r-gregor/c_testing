#include <stdio.h>
#include <string.h>
#define NUM_CHARS_IN_APLHAB 26

/**
 * V1
 */

void show_alphabet(char *array);

int main(int argc, char **argv) {

	char lower_case_abc[NUM_CHARS_IN_APLHAB];
	char upper_case_abc[NUM_CHARS_IN_APLHAB];

	for (int i=0; i < NUM_CHARS_IN_APLHAB; i++) {
		lower_case_abc[i] = 'a' + i;
		upper_case_abc[i] = 'A' + i;
	}


	show_alphabet(lower_case_abc);
	show_alphabet(upper_case_abc);

	return 0;
}



void show_alphabet(char *array) {
	for (int i = 0; i < NUM_CHARS_IN_APLHAB - 1; i++) {
		printf("%c, ", array[i]);
	}
	printf("%c\n", array[NUM_CHARS_IN_APLHAB - 1]);
}

