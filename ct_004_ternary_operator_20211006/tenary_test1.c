#include <stdio.h>

int main(void) {

	int a = 5;
	int b = 10 / 2;

	// first method
	char *response = (a == b ? "True" : "False");
	printf("Method 1: %s\n", response);

	// second method
	printf("Method 2: %s\n", (a == b ? "True" : "False"));

	// in a function
	void areTheyEqual(int x, int y) {
		printf("From function --> %d == %d: %s\n", x, y, (x == y ? "True" : "False"));
	}

	
	areTheyEqual(5, 5);
	areTheyEqual(5, 100/20);
	areTheyEqual(5, 5 + 1);


	return 0;
}