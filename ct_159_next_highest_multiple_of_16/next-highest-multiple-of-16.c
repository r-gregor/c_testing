/*
 * next highest multiple of 16
 * v1_2060518
 * from: Malloc is NOT Magic: Let´s Build it to Learn What´s Inside!
 *       https://www.youtube.com/watch?v=mYBxnojY-JA
 */
#include <stdio.h>
#include <string.h>

int next_highes_multiple_of_16(int n);

int main(int argc, char **argv) {

	int fctrs[] = {1, 8, 12, 15, 16, 17, 21, 31, 33, 57, 63, 64, 127, 129};

#if 0
	printf("Return next highest multiple of 16 (f = next_highes_multiple_of_16())\n");
	for(int n = 0; n < sizeof(fctrs) / sizeof(fctrs[0]); n++) {
		int num = fctrs[n];
		printf("f(%3d) = %d\n", num, next_highes_multiple_of_16(num));
	}
#endif

	printf("f = next_highes_multiple_of_16():\n");
	for(int n = 0; n < sizeof(fctrs) / sizeof(fctrs[0]); n++) {
		int num = fctrs[n];
		if (num < 10) {
			printf("f(%d)   = %d\n", num, next_highes_multiple_of_16(num));
		} else if (num < 100) {
			printf("f(%d)  = %d\n", num, next_highes_multiple_of_16(num));
		} else {
			printf("f(%d) = %d\n", num, next_highes_multiple_of_16(num));
		}
	}

	return 0;
}

/*
 * int result = (n + 15) >> 4 is equivalent to: int result = (int)((n + 15) / 16)
 * result << 4 is equivalent to: result * 16
 */
int next_highes_multiple_of_16(int n) {
	return ((n + 15) >> 4) << 4;
}

