/*
 * fname: include-local-library-test.c
 * 20260901 v1
 * 20260901 v2: array of string literals --> looping over and run SV_info
 * last 20260901
 */
#include <stdio.h>
#include <string.h>
#include <mylibrary.h> // loaded with '-I ./src' in gcc command ...

void SV_info(char *);


/* === MAIN === */
int main(int argc, char **argv) {

	/* v2 */
	char *fmembers[] = {
		"Hy, my name is Gregor Redelonghi",
		"My WIFE's name is Tadeja Mali Redelonghi",
		"My SON's name is Mark Redelonghi",
		"My 1-st DAUGHTER's name is Zala Redelonghi",
		"My 2-nd DAUGHTER's name is Špela Redelonghi",
		"My CAT's name is Sisi",
	};

	int num_members = sizeof(fmembers) / sizeof(fmembers[0]);
	for (int i = 0; i < num_members; i++ ) {
		SV_info(fmembers[i]);
		printf("---\n");
	}

	return 0;
} /* end main */


/* === FUNCTION DECLARATIONS == */

/*
 * convert c-string literal into sv and
 * display contents and number of characters in sv
 */
void SV_info(char *line) {
	String_View sv = SV_init(line);
	SV_print(&sv);
}

