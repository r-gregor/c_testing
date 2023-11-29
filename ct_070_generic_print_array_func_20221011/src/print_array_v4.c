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
 * v4
 * 3 print functions for 3 types
 * same invocation for each type
 * using _Generic keyword in #define statement
 * more descriptive variable names
 */
int main(int argc, char **argv) {

	int arr_of_ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char *last_name = "Redelonghi";
	char *arr_of_names[] = {"Gregor", "Tadeja", "Zala", "Mark", "Špela"};

	printf("arr_of_ints: ");
	print_array(arr_of_ints, ARR_LENGTH(arr_of_ints));

	printf("last_name: ");
	print_array(last_name, strlen(last_name));

	printf("arr_of_names: ");
	print_array(arr_of_names, ARR_LENGTH(arr_of_names));


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

