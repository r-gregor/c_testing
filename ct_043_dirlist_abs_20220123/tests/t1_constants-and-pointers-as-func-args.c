#include <stdio.h>
#include <stdlib.h>

int *num;
int num2 = 2;

void increaseByOne(int *);
void increaseByTwo();


int main(int argc, char **argv) {

	num = malloc(sizeof(int));

	printf("num before func: %d\n", *num);
	increaseByOne(num);
	printf("num after func: %d\n", *num);


	printf("num2 before func: %d\n", num2);
	increaseByOne(&num2);
	printf("num2 after func: %d\n", num2);


	printf("num2 before func2: %d\n", num2);
	increaseByTwo();
	printf("num2 after func2: %d\n", num2);

	increaseByTwo();
	increaseByTwo();
	printf("num2 after two more times func2: %d\n", num2);

	return 0;
}


void increaseByOne(int *n) {
	*n += 1;
}

void increaseByTwo() {
	num2 += 2;
}

