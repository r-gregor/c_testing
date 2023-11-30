/*
 * string_traverse_with_pointers_v1.c
 * 20230901 (en)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>   // tolower()

void display_lowercase_v1(char *str);
void display_lowercase_v2(char *str);
void crt(int n);


/* MAIN */
int main(int argc, char **argv) {

	printf("\n--- Converting string to lower case using pointers ---\n");
	char *nm = "Gregor Redelonghi THE MAGNIFICENT";
	display_lowercase_v1(nm);
	display_lowercase_v2(nm);

	crt(3);

	return 0;
} // end MAIN


/* while loop using pointers */
void display_lowercase_v1(char *str) {
	printf("%s ==> ", str);
	while (*str != '\0') {
		printf("%c", tolower(*str));
		str++;
	}
	printf("\n");
}

/* for loop using pointers */
void display_lowercase_v2(char *str) {
	printf("%s ==> ", str);
	int i = 0;
	for (; *str != '\0'; i++) {
		printf("%c", tolower(*str));
		str++;
	}
	printf("\n");
}


void crt(int n) {
	for (int i=0; i < n; i++) {
		printf("-");
	}
	printf("\n");
}

