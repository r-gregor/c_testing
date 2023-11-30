/*
 * v3
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMS2_LEN 16

int nums_len;
void show_array(int *array, size_t len);
void show_memory(int *array);

int main(int argc, char **argv) {

	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	nums_len = sizeof(nums) / sizeof(nums[0]);

	int *nums2 = malloc(NUMS2_LEN * sizeof(int));
	for (int i=0; i < NUMS2_LEN; i++) {
		*(nums2 + i) = i * 2;
	}



	printf("array = nums\n");
	printf("len(nums):  %d\n", nums_len);
	show_memory(nums);
	printf("---\n");
	show_array(nums, nums_len);
	printf("---\n");

	printf("array = nums2\n");
	printf("len(nums2):  %d\n", NUMS2_LEN);
	show_memory(nums2);
	printf("---\n");
	show_array(nums2, NUMS2_LEN);
	printf("---\n");


	return 0;
}

void show_array(int *array, size_t len) {
	printf("%-10s ", "Array idx:");
	for (int i=0; i < len; i++) {
		printf(" [%2d]", i);
	}
	printf("\n");

	printf("%-10s ", "Item:");
	for (int j=0; j < len; j++) {
		printf("%4d ", *(array + j));
	}
	printf("\n");
}

void show_memory(int *array) {
	printf("Address of array[0]:   %p\n", &array[0]);
	printf("Address of array + 1:  %p\n", array + 1);
	printf("Address of array[1]:   %p\n", &array[1]);
}

