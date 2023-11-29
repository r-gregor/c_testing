/**
 * multiple_return_v1.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LEN 256

typedef struct output {
	char sentence[MAX_LINE_LEN];
	int result;
} Output_t;

Output_t *create_output(char *sentence, int range);
bool change_output(Output_t *output, char *sentence2, int num2);

/** MAIN */
int main(int argc, char **argv) {

	Output_t *out1;

	printf("T1: ");
	if ((out1 = create_output("What a coll day!", 15)) != NULL) {
		printf("Sentence: \"%s\", result: %d\n", out1->sentence, out1->result);
	} else {
		return 1;
	}

	printf("T2: ");
	if (change_output(out1, " And It Ain't over yet!", 2)) {
		printf("Sentence: \"%s\", result: %d\n", out1->sentence, out1->result);
	} else {
		return 1;
	}

	printf("T3: ");
	if (change_output(out1, " And It Ain't over yet! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
				AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
				AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
				AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 2)) {
		printf("Sentence: \"%s\", result: %d\n", out1->sentence, out1->result);
	} else {
		return 1;
	}

	// out1 malloced inside create_output() function!!
	free(out1);


	return 0;
} // END main


/** returns a pointer to a struct with two parameters */
Output_t *create_output(char *sentence, int range) {
	int sum = 0;

	if (strlen(sentence) >= MAX_LINE_LEN) {
		printf("Sentence TO LONG!\n");
		return NULL;
	}

	Output_t *output = malloc(sizeof(Output_t));
	strcpy(output->sentence, sentence);

	for (int i=0; i < range; ++i) {
		sum += i;
	}
	output->result = sum;
	return output;
}

/** changes contents of existing struct with two parameters */
bool change_output(Output_t *output, char *sentence2, int num2) {
	size_t biglen = strlen(output->sentence) + strlen(sentence2);
	if (biglen >= MAX_LINE_LEN) {
		printf("Concatenated sentence TO LONG!\n");
		return false;
	}
	strcat(output->sentence, sentence2);
	output->result *= num2;
	return true;
}

