#include <stdio.h>
#include <string.h>
#include "test.h"

int main(int argc, char **argv) {

	say();

	int x = 6;
	int y = 7;

	printf("The sum of %d and %d is: %d\n", x, y, addi(x,y));


	return 0;
}
