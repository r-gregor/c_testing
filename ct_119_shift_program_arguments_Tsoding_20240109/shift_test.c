/*
 * from: Writing VM for my Lisp in C — Day 2
 * Tsoding Daily
 * https://www.youtube.com/watch?v=9td67NTtNCg&list=PLpM-Dvs8t0VY73ytTCQqgvgCWttV3m8LM&index=3
 * at cca: 01:13:10 / 05:28:07
 */
#include <stdio.h>
#include <string.h>

char *shift(int *argc, char ***argv) {
	char *result = **argv;
	*argv += 1;
	*argc -= 1;
	return result;
}

int main(int argc, char **argv) {
	// const char *program_name = shift(&argc, &argv);
	shift(&argc, &argv); // skip program name --> argv[0] == program_name

	if (argc == 0) {
		fprintf(stderr, "No args ... no output. Bye!\n");
		return 1;
	}
	
	int i = 0;
	while (argc != 0) {
		char *arg = shift(&argc, &argv);
		printf("arg %02d: %s\n", ++i, arg);
	}

	return 0;
}

