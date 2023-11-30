#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reversed(char *sentence, char *result);
char *reversed2(char *sentence);
void reverse_inplace(char *string);
void run_reversed2(char *sentence);
void run_reverse_inpl(char *sentence);
void hl(size_t n);

/**
 * MAIN
 */
int main(int argc, char **argv) {

	char *sentence = "ABC abc Gregor";
	printf("Original:  %s", sentence);
	printf(" -- len: %ld\n", strlen(sentence));

	char result[strlen(sentence)];

	reversed(sentence, result);
	printf("Reversed:  %s", result);
	printf(" -- len: %ld\n", strlen(result));

	hl(3); // ---

	char *sentence2 = "PopoKatePetl";
	printf("Original:  %s", sentence2);
	printf(" -- len: %ld\n", strlen(sentence2));

	char *result2;
	result2 = reversed2(sentence2);
	printf("Reversed:  %s", result2);
	printf(" -- len: %ld\n", strlen(result2));
	free(result2);

	hl(3); // ---

	char *sentence3 = "GREGOR REDELONGHI";
	run_reversed2(sentence3);
	
	hl(3); // ---

	char sentence4[] = "Tadeja Mali Redelonghi";
	// char *sentence4 = "Tadeja Mali Redelonghi"; // segmentation error !!
	run_reverse_inpl(sentence4);


	return 0;
} // end MAIN

/**
 * source AND dest and length as parameters to func
 */
void reversed(char *sentence, char *result) {
	size_t len = strlen(sentence);
	size_t i = 0;
	for (;i < len; i++) {
		result[len - i - 1] = sentence[i];
	}
	result[i] = '\0';
}


/**
 * only source as parameters to func -- malloc result inside func
 * returned as pointer --  must be freed from the outside
 */
char *reversed2(char *sentence) {
	size_t i = 0;
	size_t len = strlen(sentence);
	char *result2 = malloc(sizeof(len + 1));
	for (;i < len; i++) {
		result2[len - i - 1] = sentence[i];
	}
	result2[i] = '\0';
	return result2;
}

// from: https://www.youtube.com/watch?v=PtSHcou0WIs
void reverse_inplace(char *string) {
	// get the length of the string, use it to compute the middle index
	int length = strlen(string);
	int middle = length / 2;

	// used to swap characters on either side of the string
	char temp;

	// Swaps characters at the beginning of the string with their corresponding
	// character at the end of the string... i.e. the first character with the
	// last character, the second character with the second last character, and
	// on and on until the middle of the string is reached, at which point the
	// string will be reversed!
	for (int i = 0; i < middle; i++) {
		temp = string[i];
		string[i] = string[length - i - 1];
		string[length - i - 1] = temp;
	}
}

/**
 * uses reversed2 func to reverse a string
 * must free the pointer it receives as retuen from function
 */
void run_reversed2(char *sentence) {
	printf("Original:  %s", sentence);
	printf(" -- len: %ld\n", strlen(sentence));

	char *result;
	result = reversed2(sentence);
	printf("Reversed:  %s", result);
	printf(" -- len: %ld\n", strlen(result));
	free(result);
}

/**
 * uses reverse_inplace function
 */
void run_reverse_inpl(char *sentence) {
	printf("Original:  %s", sentence);
	printf(" -- len: %ld\n", strlen(sentence));
	reverse_inplace(sentence);
	printf("Reversed:  %s", sentence);
	printf(" -- len: %ld\n", strlen(sentence));
}

/**
 * --- delimiter ---
 */
void hl(size_t n) {
	for (int i=0; i<n; ++i) {
		printf("-");
	}
	printf("\n");
}

