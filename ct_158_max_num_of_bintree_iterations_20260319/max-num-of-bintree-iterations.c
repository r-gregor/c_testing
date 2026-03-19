/*
 * fname: max-num-of-bintree-iterations.c
 * 20260319  en v1
 * last: 20260319
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM_ELEMENTS 1000000000
#define MAX_LONG 2147483647

void get_max_num_bintree_iterations(long elnum);

int main(int argc, char **argv) {

	char errmsg[256];
	sprintf(errmsg, "[ERROR] argument must be decimal number no larger than %d\n\n", MAX_LONG);
	if (argc == 2) {
		char *mustbenum = argv[1];
		int arglen = strlen(mustbenum);
		if (arglen > 10) {
			printf("%s", errmsg);
			return -1;
		}
		for (int i = 0; i < arglen; i++) {
			if (isdigit((int)mustbenum[i]) == 0) {
			printf("%s", errmsg);
				return -1;
			}
		}
		long numel = atol(mustbenum);
		if (numel > 2147483647 || numel < 0) {
			printf("%s", errmsg);
			return -1;
		}
		get_max_num_bintree_iterations(numel);
	} else {
		get_max_num_bintree_iterations(NUM_ELEMENTS);
	}

	return 0;
}


void get_max_num_bintree_iterations(long elnum) {
	int count = 0;
	double result = (double)elnum;
	while (result / 2 >= 1) {
		result = result / 2;
		count++;
	}
	printf("Number of elements:   %ld\n", elnum);
	printf("Number of iterations: %d (max num of nodes in binary tree we have to look to)\n", count);
	printf("\n");
}

