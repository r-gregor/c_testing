#include <stdio.h>
#include <string.h>

/*
 * v2
 */

int dec2bin(char *);

int main(int argc, char **argv) {

	char *nums[] = {"1", "11", "111", "1111", "11111", "10000000", "11111111"};

	char *mynum = "10101";
	printf("binary: %-10s --> decimal: %d\n", mynum, dec2bin(mynum));

	for (int j = 0; j < sizeof(nums) / sizeof(nums[0]); j++) {
		printf("binary: %-10s --> decimal: %d\n", nums[j], dec2bin(nums[j]));
	}

	return 0;
}

/*
 * v2
 */
int dec2bin(char *numstring) {
	int numlen = strlen(numstring);

	int decnum = 0;
	int decval = 1; // instead of math.pow()
	for (int i = numlen - 1; i >=0; i--) {
		if (numstring[i] == '1') {
			decnum += decval;
		}
		decval *= 2; // instead of math.pow()
	}
	return decnum;
}
