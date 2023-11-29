#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * v1
 */

int dec2bin(char *);

int main(int argc, char **argv) {

	char *nums[] = {"1", "11", "111", "1111", "11111"};

	char *mynum = "10101";
	printf("binary: %-8s --> decimal: %d\n", mynum, dec2bin(mynum));

	for (int j = 0; j < sizeof(nums) / sizeof(nums[0]); j++) {
		printf("binary: %-8s --> decimal: %d\n", nums[j], dec2bin(nums[j]));
	}

	return 0;
}


int dec2bin(char *numstring) {
	int numlen = strlen(numstring);

	int decnum = 0;
	for (int i = 0; i < numlen; i++) {
		if (numstring[numlen - 1 - i] == '1') {
			decnum += pow(2, i);
		}
	}
	return decnum;
}
