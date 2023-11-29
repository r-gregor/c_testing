/*
 * v3
 */

#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLUMNS 5

void display_array(int *arr, int rows, int cols);

int main(int argc, char **argv) {

	int array[ROWS][COLUMNS] = {
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,1,1,1,1},
		{2,2,2,2,2},
		{3,3,3,3,3}
	};


	display_array(&array[0][0], ROWS, COLUMNS);

	float bigsum = 0.0;
	for (int c=0; c<COLUMNS; c++) {
		int csum = 0;
		for (int r=0; r<ROWS; r++) {
			csum += array[r][c];
		}
		printf("Column %d sum: %d\n", c, csum);
		printf("Column %d avg: %.1f\n", c, (csum * 1.0)/ROWS);
		printf("---\n");
		bigsum += csum;
	}
	printf("Average of all numbers in 2D array = %.1f\n", bigsum / (ROWS*COLUMNS));



	return 0;
}


void display_array(int *arr, int rows, int cols) {

	printf("array[%d][%d] = {\n", rows, cols);
	for (int r=0; r<rows-1; r++) {
		printf(" {");
		for (int c=0; c<cols-1; c++) {
			printf("%d, ", *((arr+r*rows)+c));

		}
		printf("%d},\n", *((arr+r*rows) + cols-1));
	}
	printf(" {");
	for (int r=rows-1, c=0; c<cols-1; c++) {
		printf("%d, ", *((arr+r*rows) + c));
	}
	printf("%d}\n", *((arr+(rows-1)*rows) + cols-1));
	printf("}\n");
	printf("---\n");
}

