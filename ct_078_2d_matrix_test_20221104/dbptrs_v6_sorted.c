/*
 * v6
 * from: c_access-two-dimensional-array-using-pointers_20221103.txt
 * and
 * c_5p_pass-2d-array-as-function-parameter_20221103.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void line(int n);
int *make_row();                   // v5
void show_p5(int **arr);           // v5
void show_single(int **arr, int row, int col);
void show_elements(int **arr);
bool get_rows_and_cols();

int element = 0;
int ROWS, COLS;

// main
int main(int argc, char **argv) {

	// v6: test if got correct user input
	if (get_rows_and_cols() != true) {
		return -1;
	}

	// v5
	int **nums = malloc((ROWS * COLS) * sizeof(int *));

	for (int i=0; i<ROWS; i++) {
		nums[i] = make_row();
	}

	// v5
	show_p5(nums);
	line(3);

	printf("sizeof(int): %ld\n", sizeof(int));
	for (int i=0; i < ROWS; i++) {
		printf("Addres of row-%d: %p\n", i+1, *nums + i);
	}
	line(3);

	show_elements(nums);
	line(3);

	printf("Supply M N to display element[M][N] of 2D matrix (%dx%d): ", ROWS,COLS);
	int row, col;
	scanf("%d %d", &row, &col);
	show_single(nums,row, col);

	for (int i=0; i<ROWS; i++) {
		free(nums[i]);
		nums[i] = NULL;
	}
	free(nums);
	nums = NULL;

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
void show_p5(int **arr) {
	int count = 0;
	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < COLS; j++) {
			count++;
			if (count % COLS == 0) {
				printf("%d\n", *(*(arr + i) +j));
			} else {
				printf("%d\t",  *(*(arr + i) +j));
			}
		}
	}
	printf("\n");
}

// v5
void show_single(int **arr, int row, int col) {
	if (row > ROWS || col > COLS) {
		printf("Matrix is of size %d x %d!\n", ROWS, COLS);
		return;
	}
	int M = row - 1;
	int N = col - 1;
	printf("Element [%d][%d]: %d\n", row, col, *(*(arr + M) + N));
 }

// v5
void show_elements(int **arr) {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			if ((j + 1) % COLS == 0) {
				printf("Element[%d][%d]: %d\n", i+1, j+1, *(*(arr + i) + j));
			} else {
				printf("Element[%d][%d]: %d\t", i+1, j+1, *(*(arr + i) + j));
			}
		}
	}
}

// v6
// function to return pointer to a row
// (an array of columns)
// takes in number of elements from global variable
int *make_row() {
	int *row = malloc(COLS * sizeof(int));
	for (int i=0; i<COLS; i++) {
		*(row + i) = ++element;
	}
	return row;
}

// v6
bool get_rows_and_cols() {
	printf("Enter M an N size of MxN matrix (up to 6x6): ");
	scanf("%d %d", &ROWS, &COLS);
	if (ROWS > 6 || COLS > 6) {
		printf("Matrix size should be 6x6 or less!\n");
		return false;
	}
	return true;
}
