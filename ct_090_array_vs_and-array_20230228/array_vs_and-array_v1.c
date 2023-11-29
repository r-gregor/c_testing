// fname: array_vs_and-array_v1.c
#include <stdio.h>
#include <string.h>

void print_arr(int *, int);

int main(int argc, char **argv) {

	int array[5] = {0, 0, 0, 0, 0};
	array[2] = 5;
	int arr_len = sizeof(array) / sizeof(array[0]);


	printf("case-1: Single array\n");
	printf("int array[5] = {0, 0, 0, 0, 0};\narray[2] = 5;\n");
	printf("       array contents: ");
	print_arr(array, arr_len);
	printf("                array: %p -- pointer to 1-st array element in hex (%%p)\n", array);
	printf("                array: %zu -- pointer to 1-st array element in bin (%%zu)\n", (size_t) array);
	printf("            array + 1: %zu -- pointer to 1-st element + 1* sizeof(element)      = + 1*4\n", (size_t) (array + 1));
	printf("               &array: %zu -- pointer to entire array\n",  (size_t) &array);
	printf("           &array + 1: %zu -- pointer to entira array + 1* sizeof(entire array) = + 5*4\n", (size_t) (&array + 1));
	printf("---\n");
	printf("case-2: 2D matrix\n");
	printf("int matrix[3][5] = {\n"
	"	{ 0,  1,  2,  3,  4},\n"
	"	{ 5,  6,  7,  8,  9},\n"
	"	{10, 11, 12, 13, 14}\n"
	"}\n");

	int matrix[3][5] = {
		{0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9},
		{10, 11, 12, 13, 14}
	};

	printf("\n");
	printf("            matrix[1]: %zu -- pointer to 1-st element of row 2\n", (size_t) matrix[1]);
	printf("        matrix[1] + 1: %zu -- pointer to 1-st element of row 2 + (1* sizeof(element) = + 1*4)\n", (size_t) (matrix[1] + 1));
	printf("         *(matrix[1]): %zu\n", (size_t) *(matrix[1]));
	printf("     *(matrix[1] + 1): %zu\n", (size_t) *(matrix[1] + 1));
	printf("           &matrix[1]: %zu -- pointer to entire row 2\n", (size_t) &matrix[1]);
	printf("       &matrix[1] + 1: %zu -- pointer to entire row 2 + (1* sizeof(row)              = + 5*4)\n", (size_t) (&matrix[1] + 1));
	printf("        *(&matrix[1]): %zu\n", (size_t) *(&matrix[1]));
	printf("     *(*(&matrix[1])): %zu\n", (size_t) *(*(&matrix[1])));
	printf("    *(&matrix[1] + 1): %zu\n", (size_t) *(&matrix[1] + 1));
	printf(" *(*(&matrix[1] + 1)): %zu\n", (size_t) *(*(&matrix[1] + 1)));


	return 0;
}


void print_arr(int *arr, int len) {
	printf("{");
	for (int i=0; i < len - 1; i++) {
		printf("%zu, ", (size_t) arr[i]);
	}
	printf("%zu}\n", (size_t) arr[len - 1]);
}

