/*
 * filename: array-of-structs-sort-test_v1.c
 * 202602121 v1 en: using pointer to entire struct 'Object_t (*arr)[]'
 * last: 20260121
 */
#include <stdio.h>
#include <string.h>

typedef struct object {
	// char line[256];
	char *line;
	size_t size;
	float flag;
} Object_t ;

void print_array(Object_t *arr, size_t size);
void print_array_ptr(Object_t (*arr)[], size_t size);

/* main */
int main(int argc, char **argv) {

	/* array of structs Object_t declaration + initialization */
	Object_t array_of_structs[] = {
		{"Name1", 5, 1.0},
		{"AAjA", 12, 1.0},
		{"GuGu", 4, 1.5},
		{"nmcc1", 25, 0.5},
		{"NASA", 51, 1.5},
		{"IRS", 7, 1.5},
		{"MaGa", 9, 1.0},
		{"RgregoR", 1, 0.0},
		{"NSI", 22, 1.5},
		{"KISS", 105, 1.0}
	};

	size_t arr_size = sizeof(array_of_structs) / sizeof(array_of_structs[0]);

	/* print-1: print an array of structs */
	/* array_of_structs == &array_of_structs[0] */
	print_array(array_of_structs, arr_size);

	/* --- */

	/* pointer to an entire array of structs */
	Object_t (*aos_ptr)[arr_size] = &array_of_structs;

	/* print-2: print a pointer to an array of structs */
	print_array_ptr(aos_ptr, arr_size);


	return 0;
} // end main

/* printing array of structs */
void print_array(Object_t *arr, size_t size) {
	printf("Printing an array of structs Object_t:\n");
	printf("%-10s ::  %4s  :: %5s\n",  "line", "size","flag");
	printf("------------------------------\n");
	for (int i=0; i < size; ++i) {
		printf("%-10s ::  %4ld  :: %4.1f\n",  arr[i].line, arr[i].size, arr[i].flag);
	}
	printf("\n");
}


/* printing pointer to array of structs */
void print_array_ptr(Object_t (*arr)[], size_t size) {
	printf("Printing a pointer to an array of structs Object_t (for loop):\n");
	printf("%-10s ::  %4s  :: %5s\n",  "line", "size","flag");
	printf("------------------------------\n");

	/* with for loop ... */
	for (int i=0; i < size; ++i) {
		printf("%-10s ::  %4ld  :: %4.1f\n",  (*arr + i)->line, (*arr + i)->size, (*arr + i)->flag);
	}
	printf("\n");

	printf("Printing a pointer to an array of structs Object_t (while loop):\n");
	printf("%-10s ::  %4s  :: %5s\n",  "line", "size","flag");
	printf("------------------------------\n");
	/* with while loop ... */
	int i=0;
	while(i < size) {
		Object_t *arrv = (*arr) + i;
		printf("%-10s ::  %4ld  :: %4.1f\n",  arrv->line, arrv->size, arrv->flag);
		i++;
	}
	printf("\n");
}

