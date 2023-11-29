#include <stdio.h>
#include <string.h>

#define ARR_LENGTH(ARR) sizeof(ARR)/sizeof(ARR[0])

/*
 * v2
 * 2 print functions for 2 types
 * separate invocation for each type
 */

void print_int_array(int *array, int len);
void print_str_array(char **array, int len);

int main(int argc, char **argv) {

	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len1 = ARR_LENGTH(arr1);

	char *names[] = {"Gregor", "Tadeja", "Zala", "Mark", "Špela"};
	int len2 = ARR_LENGTH(names);

	// test
	// printf("Length of arr1: %d\n", len1);

	printf("Array arr1: ");
	print_int_array(arr1, len1);

	printf("Array names: ");
	print_str_array(names, len2);


	return 0;
}


void print_int_array(int *array, int len) {
	for (int i=0; i < len - 1; i++) {
		printf("%d, ", *(array + i));
	}
	printf("%d\n", *(array + (len - 1)));
}

void print_str_array(char **array, int len) {
	for (int i=0; i < len - 1; i++) {
		printf("%s, ", *(array + i));
	}
	printf("%s\n", *(array + (len - 1)));
}

