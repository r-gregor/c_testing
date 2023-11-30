#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	for (int i = 1; i < 101; i++) {
		if (i % 3 == 0 && i % 5 == 0) printf("num %3d:FizzBuzz\n", i);
		else if (i % 3 == 0) printf("num %3d: Fizz\n", i);
		else if (i % 5 == 0) printf("num %3d: Buzz\n", i);
		else printf("num %3d: %d\n", i, i);
	}

	return 0;
}
