#include <stdio.h>
#include <string.h>

void disp_arr(int *array, int arr_len);
void disp_arr_rev1(int *array, int arr_len);
void disp_arr_rev2(int *array, int arr_len);

/**
 * MAIN
 */
int main(int argc, char **argv) {

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr_len = sizeof(arr)/sizeof(int);
	int *item;

#if 1
	printf("Displaying array with for loop directly:\n");
	item = arr;
	for (int i = 0; i < arr_len - 1; ++i) {
		printf("%d, ", *item);
		item++;
	}
	printf("%d\n", *item);
	printf("---\n");
#endif

	// first loop
	item = arr;
	disp_arr(item, arr_len);
	printf("---\n");

	// second loop
	item = arr;
	disp_arr_rev1(item, arr_len);
	printf("---\n");

	// third loop
	item = arr;
	disp_arr_rev2(item, arr_len);


	return 0;
} // end MAIN

/** FIRST func */
void disp_arr(int *array, int arr_len) {
	printf("disp_arr() func: displaying array with for loop:\n");
	for (int i = 0; i < arr_len - 1; ++i) {
		printf("%d, ", *array);
		array++;
	}
	printf("%d\n", *array);
}

/** SECOND func */
void disp_arr_rev1(int *array, int arr_len) {
	printf("disp_arr_rev1() func: displaying array with while loop - reversed:\n");
	int count = 0;
	while (count < arr_len - 1)   {
		printf("%d, ", *(array + arr_len - 1 - count));
		count++;
	}
	printf("%d\n", *(array + arr_len - 1 - count));
}

/** THIRD func */
void disp_arr_rev2(int *array, int arr_len) {
	printf("disp_arr_rev2() func: displaying array with while loop - reversed:\n");
	while (arr_len > 1) {
		printf("%d, ", *(array + --arr_len));
	}
	printf("%d\n", *(array + --arr_len));
}

