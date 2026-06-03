/*
 * v1
 */

#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 3

void show(int arr[ROWS][COLS]);
void line(int n);

int main(int argc, char **argv) {

	int nums[ROWS][COLS] = {{1,2,3}, {4,5,6}, {7,8,9}};

	show(nums);
	line(3);

	return 0;
}

/*
 * function to display 2D array elements
 * passing 2D array as value
 */
void show(int arr[ROWS][COLS]) {
	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < COLS - 1; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("%d\n", arr[i][COLS - 1]);
	}
}


void line(int n) {
	for (int i=0; i < n; i++) {
		printf("-");
	}
	printf("\n");
}

