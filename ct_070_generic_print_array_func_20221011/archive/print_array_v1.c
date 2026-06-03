#include <stdio.h>
#include <string.h>

#define ARR_LENGTH(ARR) sizeof(ARR)/sizeof(ARR[0])

/*
 * v1
 * single print function for single type
 */

void print_array(int *array, int len);

int main(int argc, char **argv) {

	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length1 = ARR_LENGTH(arr1);

	// test
	// printf("Length of arr1: %d\n", length);

	print_array(arr1, length1);


	return 0;
}



void print_array(int *array, int len) {
	for (int i=0; i < len - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[len - 1]);
}

