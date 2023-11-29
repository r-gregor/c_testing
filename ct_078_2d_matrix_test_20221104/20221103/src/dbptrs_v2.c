/*
 * v2
 * from: c_access-two-dimensional-array-using-pointers_20221103.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void line(int n);
void show_p(int (*arr)[COLS]);

// main
int main(int argc, char **argv) {

	int nums[ROWS][COLS] = {{1,2,3}, {4,5,6}, {7,8,9}};

	// v2
	show_p(nums);
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
 * v2
 * function to display 2D array (matrix)
 * using pointers (pass by reference)
 */
void show_p(int (*arr)[COLS]) {
	for (int i=0; i < ROWS; i++) {
		for (int j=0; j < COLS - 1; j++) {
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("%d\n", *(*(arr + i) + COLS - 1));
	}
}

