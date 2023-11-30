/*
 * v2
 */

#include <stdio.h>
#include <string.h>

size_t nums_len;
void show_array(int *array, size_t len);

int main(int argc, char **argv) {

	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	nums_len = sizeof(nums) / sizeof(nums[0]);

	printf("Base address of array: %p\n", nums);
	printf("Address of array[0]:   %p\n", &nums[0]);
	printf("Address of array + 1:  %p\n", nums + 1);
	printf("Address of array[1]:   %p\n", &nums[1]);
	printf("---\n");

	show_array(nums, nums_len);
	printf("---\n");


	return 0;
}

void show_array(int *array, size_t len) {
	printf("%-10s ", "Array:");
	for (int i=0; i < len; i++) {
		printf(" [%d]", i);
	}
	printf("\n");

	printf("%-10s ", "Items:");
	for (int j=0; j < len; j++) {
		printf("  %d ", *(array + j));
	}
	printf("\n");
}

