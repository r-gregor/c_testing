#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int argc, char **argv) {

	for (float i = 6.0; i < 200; i += 12.8) {
		float num = i/3.33;
		printf("Num:%10f, Floor:%3.0f, Ceil:%3.0f\n", num, floor(num), ceil(num));
	}

	return 0;
}

