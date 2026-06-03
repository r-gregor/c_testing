/**
 * multiple_return_v3.c
 * changes in create_output():
 *   - function input parameters as const
 *   - no return value, output becomes third function patrameter:
 *     pointer to new struct allocated on the stack in main()
 *     no need to allocate on heap and free
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 256

typedef struct output {
	char sentence[MAX_LINE_LEN];
	int result;
} Output_t;

bool create_output(Output_t *output, const char *sentence, const int range);
bool change_output(Output_t *output, const char *sentence2, const int num2);

/** MAIN */
int main(int argc, char **argv) {

	Output_t out1;

	printf("T1: ");
	if (create_output(&out1, "What a coll day!", 15)) {
		printf("Sentence: \"%s\", result: %d\n", out1.sentence, out1.result);
	} else {
		return 1;
	}

	printf("T2: ");
	if (change_output(&out1, " And It Ain't over yet!", 2)) {
		printf("Sentence: \"%s\", result: %d\n", out1.sentence, out1.result);
	} else {
		return 1;
	}

	printf("T3: ");
	if (change_output(&out1, " And It Ain't over yet! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
				AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
				AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
				AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 2)) {
		printf("Sentence: \"%s\", result: %d\n", out1.sentence, out1.result);
	} else {
		return 1;
	}

	// no more needed!
	// free(out1);


	return 0;
} // END main


/** UPDATES an existing pointer to a struct */
bool create_output(Output_t *output, const char *sentence, const int range) {
	int sum = 0;

	if (strlen(sentence) >= MAX_LINE_LEN) {
		printf("Sentence TO LONG!\n");
		return false;
	}
	
	strcpy(output->sentence, sentence);

	for (int i=0; i < range; ++i) {
		sum += i;
	}
	output->result = sum;
	return true;
}

/** changes contents of existing struct with two parameters */
bool change_output(Output_t *output, const char *sentence2, const int num2) {
	size_t biglen = strlen(output->sentence) + strlen(sentence2);
	if (biglen >= MAX_LINE_LEN) {
		printf("Concatenated sentence TO LONG!\n");
		return false;
	}
	strcat(output->sentence, sentence2);
	output->result *= num2;
	return true;
}

