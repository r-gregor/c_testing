#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 36

int main(int argc, char **argv) {

	srand(time(0));


	for (int i=0; i < RANGE; i++) {
		printf("%d ", rand() % (RANGE + 1));
	}
	printf("\n");


	return 0;
}

