#include <stdio.h>
#include <string.h>
#include <stdlib.h>

div_t result;

int main(void) {

	result = div(7, 3);

	printf("Dividinq two integers '7/3':\n");
	printf("quotient: %d\nreminder: %d\n", result.quot, result.rem);


	return 0;
}
