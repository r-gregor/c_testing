#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const int CHARP = 5;		// "Char" padding
const int ASCIIP = 8;		// "ASCII" padding
const int MAXCOLUMNS = 10;
const int MINCOLUMNS = 1;

void usage(char *arg) {
	printf("Usage: %s [ n ]\n", arg);
	printf("			n .... number of columns\n");
	printf("			       optional (default = 3)\n\n");
	exit(1);
}

void crta(int n) {
	while(n != 0) {
		printf("-");
		n--;
	}
	printf("\n");
}

void print_header(int ncols) {
	int nlines = (CHARP + ASCIIP)*(ncols-1)  + (CHARP + strlen("ASCII"));

	/* header */
	crta(nlines);
	// printf("Char ASCII   Char ASCII   Char ASCII\n");
	for (int j=0; j<ncols - 1; j++) {
		printf("%-*s%-*s", CHARP, "Char", ASCIIP, "ASCII");
	}
	printf("%-*s%-*s\n", CHARP, "Char",ASCIIP, "ASCII");
	crta(nlines);
}

void ascii_char_codes(char *array, int ncols) {
	printf("\n");
	size_t len1 = strlen(array);

	/* header */
	print_header(ncols);

	int cnt = 0;
	for (int i=0; i<len1; i++) {
		cnt++;
		char c2 = array[i];
		if (cnt % ncols == 0) {
			printf("%-5c%-8d\n", c2, c2);
		} else {
			printf("%-5c%-8d", c2, c2);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {

	/* default columns num*/
	int ncols = 3;
	
	if (argc == 2) {
		int larg = (int)(*argv[1]);
		int larg_v = atoi(argv[1]);
		if (isdigit(larg) && !(larg_v < MINCOLUMNS) && larg_v < MAXCOLUMNS) {
			ncols = larg_v;
		} else {
			usage(argv[0]);
		}
	} 
	
	if (argc > 2) {
		usage(argv[0]);
	}

	const char myname[] = "Gregor";
	printf("The length of string \"%s\" is: %ld.\n",  myname, strlen(myname));
	printf("The 'sizeof' of \"%s\" is: %ld.\n", myname, sizeof(myname));

	int len = (sizeof(myname) / sizeof(char)) - 1;

	for (int i=0; i < len; i++) {
		int c1 = (int) myname[i];
		if isupper(c1) {
			printf("Char %c (%d) is UpperCase.\n", c1, c1);
		} else {
			printf("Char %c (%d) is lowerCase.\n", c1, c1);
		}
	}

	char lcl[] = "abcdefghijklmnopqrstuvwxyz";
	char ucl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char nml[] = "0123456789";

	int mycols = 1;

	ascii_char_codes((char*) lcl, ncols);
	ascii_char_codes((char*) ucl, ncols);
	ascii_char_codes((char*) nml, mycols);

	return 0;
}
