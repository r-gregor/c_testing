#include <stdio.h>

int main() {

	printf("The scull: %s\n", "\xE2\x98\xA0");
	printf("%s, ", "\xc2\xae");
	printf("%s, ", "\u00ae");
	printf("%s, ", "\u00D0");
	printf("%s, ", "\u2586");
	printf("%s, ", "\u0416");
	printf("%s, ", "\u1405");
	printf("%s, ", "\u2230");
	printf("%s, ", "\u270C");
	printf("N%s,\n", "\u00B2");
	printf("%s4 = 2, ", "\u221A");

/*
 * 	for (int i=0; i<11; i++) {
 * 		printf("%s", "\u2586");
 * 	}
 * 	printf("\n");
 */
	printf("\n");

	return 0;
}


