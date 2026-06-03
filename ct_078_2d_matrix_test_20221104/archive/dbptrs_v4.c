/*
 * v4
 * from: c_access-two-dimensional-array-using-pointers_20221103.txt
 * and
 *       c_5p_pass-2d-array-as-function-parameter_20221103.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void line(int n);
void show_p3(int **arr);           // v4
void show_single(int **arr, int row, int col);
void show_elements(int **arr);

// main
int main(int argc, char **argv) {

	// v4
	int **nums = malloc(ROWS * sizeof(int *));
	for (int j=0; j < COLS; j++) {
		*(nums + j) = malloc(COLS * sizeof(int));
	}

	if (nums == NULL) {
		printf("Could not allocate memory for nums!\n");
		return -1;
	}

	int elements = 0;
	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < COLS; j++) {
			// nums[i][j] = ++elements * 2;
			*(*(nums + i) + j) = ++elements * 2;
		}
	}


	// v4
	show_p3(nums);
	line(3);


	printf("sizeof(int): %ld\n", sizeof(int));
	for (int i=0; i < ROWS; i++) {
		printf("Addres of row-%d in nums: %p\n", i+1, *nums + i);
	}
	line(3);

	show_elements(nums);
	line(3);

	printf("Supply M N for MxN 2D matrix (3x3): ");
	int row, col;
	scanf("%d %d", &row, &col);
	show_single(nums,row, col);


	free(nums);
	return 0;
} // end main


void line(int n) {
	for (int i=0; i < n; i++) {
		printf("-");
	}
	printf("\n");
}

/*
 * v4
 * function to display 2D array (matrix)
 * using double pointers
 */
void show_p3(int **arr) {
	int count = 0;
	for (int k=0; k < ROWS * COLS; k++) {
		count++;
		if (count % COLS == 0) {
			printf("%d\n", **arr + k);
		} else {
			printf("%d\t", **arr + k);
		}
	}
	printf("\n");
}

void show_single(int **arr, int row, int col) {
	if (row > ROWS || col > COLS) {
		printf("Matrix is of size %d x %d!\n", ROWS, COLS);
		return;
	}
	int M = row - 1;
	int N = col - 1;
	printf("Element [%d][%d]: %d\n", row, col, **arr + (M * COLS) + N);
 }

void show_elements(int **arr) {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			printf("Element[%d][%d]: %d\n", i+1, j+1, **arr + (i * COLS) + j);
		}
	}
}

