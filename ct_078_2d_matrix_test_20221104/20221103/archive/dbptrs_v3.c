/*
 * v3
 * from: c_access-two-dimensional-array-using-pointers_20221103.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void line(int n);
void show_p2(int (*arr)[COLS]);    // v3

// main
int main(int argc, char **argv) {

	int nums[ROWS][COLS] = {{1,2,3}, {4,5,6}, {7,8,9}};

	// v3
	show_p2(nums);
	line(3);

	printf("sizeof(int): %ld\n", sizeof(int));
	for (int i=0; i < ROWS; i++) {
		printf("Addres of %d-st ROW in nums: %p\n", i+1, nums + i);
	}
	line(3);

	return 0;
} // end main


void line(int n) {
	for (int i=0; i < n; i++) {
		printf("-");
	}
	printf("\n");
}

/*
 * v3
 * function to display 2D array (matrix)
 * using pointers (pass by reference)
 */
void show_p2(int (*arr)[COLS]) {
	int count = 0;
	for (int k=0; k < ROWS * COLS; k++) {
		count++;
		if (count % 3 == 0) {
			printf("%d\n", **arr + k);
		} else {
			printf("%d\t", **arr + k);
		}
	}
	printf("\n");
}

