#include <stdio.h>
#include <string.h>

void updateNum(int *N);

int main(int argc, char **argv) {

	int num = 1;
	
	for (int i=0; i<6; i++) {
		updateNum(&num);
		printf("num = %d\n", num);
	}

	return 0;
}

void updateNum(int *N) {
	if (*N == 0) {
		*N = 1;
		printf("num = %d\n", *N);
	}

	*N += (*N) * 2;
}
