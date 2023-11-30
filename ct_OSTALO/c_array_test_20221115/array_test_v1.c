/*
 * v1
 */

#include <stdio.h>
#include <string.h>

void show_item(int *array);
void show_array(int *array, size_t len);
size_t nums_len;

int main(int argc, char **argv) {

	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	nums_len = sizeof(nums) / sizeof(nums[0]);

	printf("Base address of array: %p\n", nums);
	printf("Address of arrayi[0]: %p\n", &nums[0]);

	show_array(nums, sizeof(nums)/sizeof(nums[0]));

	printf("---\n");

	show_item(nums);


	return 0;
}

void show_item(int *array) {

	int element;
	printf("Element index to display: ");
	scanf("%d", &element);

	if (element >= nums_len) {
		printf("Elelment %d out of array!\n", element);
		return;
	}
	printf("Item array[%d] = %d\n", element, *(array + element));
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

