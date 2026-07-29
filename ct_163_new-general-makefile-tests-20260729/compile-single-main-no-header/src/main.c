#include <string.h>
#include <stdio.h>

/* declarations */
void say(void);
int addi(int a, int b);

/* definitions */
void say(void) {
	printf("This is all so Amazing!\n");
}

int addi(int a, int b) {
	return a + b;
}

/* main */
int main(int argc, char **argv) {

	say();

	int x = 6;
	int y = 7;

	printf("The sum of %d and %d is: %d\n", x, y, addi(x,y));


	return 0;
}
