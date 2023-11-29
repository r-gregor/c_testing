#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

// main
int main(int argc, char **argv) {

	// int nums[ROWS][COLS] = {0};
	int *nums = malloc((ROWS * COLS) * sizeof(int));
	int elements = 0;

	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < COLS; j++) {
			// *(nums + i * COLS + j) = ++elements * 2;
			nums[i * COLS + j] = ++elements * 2;
		}
	}

	printf("addres of nums:     %p\n", nums);
	printf("addres of &nums[0]: %p\n", &nums[0]);

	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < ROWS; j++) {
			// printf("nums[%d][%d] = %d\n", i, j, *(nums + i * COLS + j));
			printf("nums[%d][%d] = %d\n", i, j, nums[i * COLS + j]);
		}
	}
	printf("\n");

	return 0;
} // end main

