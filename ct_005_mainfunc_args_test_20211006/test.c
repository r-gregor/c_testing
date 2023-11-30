#include <stdio.h>
#include <stdbool.h>

/*
 * horizontal line
 */
void hl() {
	printf("---------------------------------------------\n");
}

/*
 * single line printout of main func args
 */
void print_out_single_line(int argnum, char **args) {
	printf("Printing args in single line:\n");
	if (argnum < 2) {
		printf("No args!\n");
		printf("Programm name: %s\n", args[0]);
	}
	printf("Programm name: %s\n", args[0]);
	printf("Args num: %d\n", argnum);
	printf("Full line: %s %s", args[0]);
	for (int i=1; i < argnum; i++) {
		printf("\"%s\" ", args[i]);
	}
	printf("\n");
}

/*
 * multiple line printout of main func args
 */
void print_out_multple_lines(int argnum, char **args) {
	printf("Printing args in multiple lines:\n");
	if (argnum < 2) {
		printf("No args!\n");
		printf("Programm name: %s\n", args[0]);
	}
	
	printf("Programm name: %s\n", args[0]);
	printf("Args num: %d\n", argnum);
	for (int i=1; i < argnum; i++) {
		printf("%s\n", args[i]);
	}
	printf("\n");
}

/* main */
int main(int argc, char **argv) {

	hl();
	print_out_single_line(argc, argv);
	hl();
	print_out_multple_lines(argc, argv);
	
	
	return 0;
A
}