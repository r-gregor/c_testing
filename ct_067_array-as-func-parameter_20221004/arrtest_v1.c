#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_EL 20
#define TEST_value 23


int putInt(int *array, int value, int size);
int printArray(int *array, int size);

int main(int argc, char **argv) {

	int size = 0;
	int arr[MAX_ARRAY_EL];


	for (int i = 1; i < TEST_value; i++) {
		putInt(arr, i, size);
		size++;
	}

	printf("%d elements added to an array.\n", size);

	printArray(arr, size);

	return 0;
}


int putInt(int *array, int value, int size) {

	if (size < MAX_ARRAY_EL - 1) {
		array[size] = value;
		return 1;
	} else {
		printf("Arrayfull!\n");
		return -1;
	}

}

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

