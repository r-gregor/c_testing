#include <stdio.h>
#include <string.h>

#define ARR_LENGTH(ARR) sizeof(ARR)/sizeof(ARR[0])

#define print_array(data, n)           \
  _Generic((*data),                    \
           int: print_int,             \
           char: print_chr,            \
           char *: print_str)(data,n)  \

void print_int(int *array, int len);
void print_chr(char *array, int len);
void print_str(char **array, int len);

/*
 * v3
 * 3 print functions for 3 types
 * same invocation for each type
 * using _Generic keyword in #define statement
 */
int main(int argc, char **argv) {

	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len1 = ARR_LENGTH(arr1);

	char *last_name = "Redelonghi";
	// int len2 = ARR_LENGTH(names);

	char *names[] = {"Gregor", "Tadeja", "Zala", "Mark", "Špela"};
	int len2 = ARR_LENGTH(names);

	// test
	// printf("Length of arr1: %d\n", len1);

	printf("Array arr1: ");
	print_array(arr1, len1);

	printf("String last_name: ");
	print_array(last_name, strlen(last_name));

	printf("Array names: ");
	print_array(names, len2);


	return 0;
}


void print_int(int *array, int len) {
	for (int i=0; i < len - 1; i++) {
		printf("%d, ", *(array + i));
	}
	printf("%d\n", *(array + (len - 1)));
}

void print_chr(char *array, int len) {
	for (int i=0; i < len - 1; i++) {
		printf("%c, ", *(array + i));
	}
	printf("%c\n", *(array + (len - 1)));
}

void print_str(char **array, int len) {
	for (int i=0; i < len - 1; i++) {
		printf("%s, ", *(array + i));
	}
	printf("%s\n", *(array + (len - 1)));
}

