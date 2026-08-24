/*
 * fname: check-arguments.c
 * check args to a command to see what expansion BASH does
 * to avoid to accidently rm something important
 * 20260824 v1
 * last: 20260824
 */

#include <stdio.h>

void print_args(int argc, char **argv);
void print_command(int argc, char **argv);

/* main */
int main(int argc, char **argv) {

	if (argc < 2) {
		printf("[INFO] Got 0 arguments\n\n");
		return 1;
	}

	print_args(argc, argv);
	print_command(argc, argv);

	return 0;
} /* end main */

/* print all args if any */
void print_args(int argc, char **argv) {
	printf("[INFO] got %d arguments:\n", argc - 1);
	for (int i=1; i < argc; i++) {
		printf("arg %02d: %s\n", i, argv[i]);
	}
	printf("---\n");
}

/* print what a <command> with args would look like */
void print_command(int argc, char **argv) {
	char CMMND[256];
		sprintf(CMMND, "\e[31m%s\e[0m", "<COMMAND>");
	// printf("$> <COMMAND>");
	printf("$> %s", CMMND);
	for (int i=1; i < argc; i++) {
		printf(" %s", argv[i]);
	}
	printf("\n\n");
}

