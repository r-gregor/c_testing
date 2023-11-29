// fname: array_vs_and-array_v2.c

/*
 * v2: calloc array
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_arr(int *, int);

int main(int argc, char **argv) {

	int num_elements = 5;
	int *array = calloc(num_elements, sizeof(int)); // don't forget to free array!!
	array[2] = 5;
	int arr_len = num_elements;


	printf("*** case-1: Single array ***\n");
	printf("int num_elements = 5;\nint *array = calloc(num_elements, sizeof(int));\narray[2] = 5;\n");
	printf("       array contents: ");
	print_arr(array, arr_len);
	printf("(1)                array: %p  -- pointer to 1-st array element in hex (%%p)\n", array);
	printf("(2)                array: %zu -- pointer to 1-st array element in bin (%%zu)\n", (size_t) array);
	printf("(3)            array + 1: %zu -- pointer to 1-st element + 1* sizeof(element)      = + 1*4\n", (size_t) (array + 1));
	printf("(4)               &array: %zu -- address of allocated pointer to entire array\n",  (size_t) &array);
	printf("(5)            *(&array): %zu -- value of (4)\n",  (size_t) *(&array));
	printf("(6)           &array + 1: %zu -- address (4) + 1* sizeof(pointer) = + 1*8\n", (size_t) (&array + 1));
	printf("---\n");
	printf("stack allocared int array[5] is different as heap allocated memory or array of 5 ints:\n");
	printf("Check out: c_why-do-array-and-andarray-pointing-to-same-address_20230309.txti\n");
	printf("           [https://stackoverflow.com/questions/54807208/why-are-array-and-array-pointing-to-the-same-address]\n");
	printf("---\n");
	printf("*** case-2: 2D matrix ***\n");
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

	free(array);


	return 0;
}


void print_arr(int *arr, int len) {
	printf("{");
	for (int i=0; i < len - 1; i++) {
		printf("%zu, ", (size_t) arr[i]);
	}
	printf("%zu}\n", (size_t) arr[len - 1]);
}


