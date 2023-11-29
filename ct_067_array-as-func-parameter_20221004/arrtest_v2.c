#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_EL 20
#define TEST_value 23


void putInt(int *array, int value, int size);
int printArray(int *array, int size);

int main(int argc, char **argv) {

	int size = 0;
	int arr[MAX_ARRAY_EL];

	printf("Trying to add %d elements to an array of size %d.\n", TEST_value, MAX_ARRAY_EL);
	printf("Adding ");
	for (int i = 0; i < TEST_value; i++) {
		if (i == MAX_ARRAY_EL) {
			printf(" array full at index %d!\n", i);
			break;
		}

		printf(".");
		putInt(arr, i, size);
		size++;
	}

	printf("%d elements added to an array.\n", size);

	printArray(arr, size);

	return 0;
}

/*
 * If array is a parameter in function call it's size
 * cannot be determined by sizeof() function, because
 * array decays to a pointer.
 * So valueber of elements -> size must be supplied to
 * a function as parameter. The size must be updated
 * from outside of the calling function!
 */
void putInt(int *array, int value, int size) {
	array[size] = value;
}

/*
 * SAME AS PREVIOUS!
 */
int printArray(int *array, int size) {

	if (size <= 0) {
		printf("Array empty!\n");
		return -1;
	}

	printf("Array elements: ");

	for (int j = 0; j < size - 2; j++) {
			printf("%d, ", array[j]);
	}
	printf("%d\n", array[size - 1]);

	return 1;
}

