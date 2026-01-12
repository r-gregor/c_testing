/*
 * filename: get_arr_el_count.c
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	int arr_i[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	size_t arr_i_elnum = sizeof(arr_i) / sizeof(arr_i[0]);     // 10

	/* usual way */
	printf("Num of elements: %ld\n", arr_i_elnum);

	/* special way:
	(from: https://www.geeksforgeeks.org/c/length-of-array-in-c/)
	---
	&arr        ... gives the address of the entire array.
	&arr + 1    ... moves the pointer to the address just after the end of the array arr.
	*(&arr + 1) ... dereferences this pointer to get the memory location just after the array.
	
	Subtracting the base address of the array (arr) from this value gives the total number
	of elements in the array, as pointer arithmetic works based on the size of the elements
	(e.g., int in this case). */
	printf("Num of elements: %ld\n", *(&arr_i + 1) - arr_i);   // 10

	return 0;
}

