/*
 * filename: array-of-structs-sort-test_v3.c
 * 20260121 v1 en: using pointer to entire struct 'Object_t (*arr)[]'
 * 20260122 v2 en: using array of pointers to structs to print sorted
 *                 array without touching the original array of structs
 * 20260123 v3 en: added sorts by line and by size
 *                 formated print of each array with getchar() to continue
 * last: 20260122
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct object {
	char *line;
	unsigned int id;
	size_t size;
	float flag;
} Object_t ;

void print_header();
void print_arr(Object_t *arr, size_t size);
void print_arr_ptr(Object_t **arr_ptr, size_t size);
int cmpfunc_line(const void *a, const void *b);
int cmpfunc_size(const void *a, const void *b);

/* ========== main ============== */
int main(int argc, char **argv) {

	/* array of structs Object_t declaration + initialization */
	Object_t array_of_structs[] = {
		{"Name1", 1, 5, 1.0},
		{"AAjA", 2, 12, 1.0},
		{"GuGu", 3, 4, 1.5},
		{"nmcc1", 4, 25, 0.5},
		{"NASA", 5, 51, 1.5},
		{"IRS", 6, 7, 1.5},
		{"MaGa", 7, 9, 1.0},
		{"RgregoR", 8, 1, 0.0},
		{"NSI", 9, 22, 1.5},
		{"KISS", 10, 105, 1.0}
	};

	/* size of array */
	size_t arr_size = sizeof(array_of_structs) / sizeof(array_of_structs[0]);

	/* array of pointers to structst */
	Object_t *array_of_structs_ptrs[arr_size];
	for (int i=0; i<arr_size; ++i) {
		array_of_structs_ptrs[i] = &array_of_structs[i];
	}

	/* print original array */
	printf("Original array of structs:\n");
	print_arr(array_of_structs, arr_size);
	printf("\n");
	getchar();

	/* print unsorted array of pointers */
	/*
	print_arr_ptr(array_of_structs_ptrs, arr_size);
	printf("\n");
	getchar();
	*/

	/* print array of pointers sorted by line string */
	printf("Array of structs sorted by line string:\n");
	qsort(array_of_structs_ptrs, arr_size, sizeof(Object_t *), cmpfunc_line);
	print_arr_ptr(array_of_structs_ptrs, arr_size);
	printf("\n");
	getchar();

	/* print array of pointers sorted by size number */
	printf("Array of structs sorted by size number:\n");
	qsort(array_of_structs_ptrs, arr_size, sizeof(Object_t *), cmpfunc_size);
	print_arr_ptr(array_of_structs_ptrs, arr_size);
	printf("\n");


	return 0;
} // end main


/* ======= FUNCTION DECLARATIONS ============ */

void print_header() {
	printf("%-3s %10s | %6s | %6s\n", "id:", "line", "size", "flag");
	printf("================================\n");
}

/* print array of structs */
void print_arr(Object_t *arr, size_t size) {
	print_header();
	for (int j=0; j<size; ++j) {
		/*
		printf("%02d: %10s | %6ld | %6.2f\n",
				arr[j].id,
				arr[j].line,
				arr[j].size,
				arr[j].flag);
		... same as ... */
		printf("%02d: %10s | %6ld | %6.2f\n",
				(*(arr + j)).id,
				(*(arr + j)).line,
				(*(arr + j)).size,
				(*(arr + j)).flag);
	}
}

/* print array of pointers to structs */
void print_arr_ptr(Object_t **arr_ptr, size_t size) {
	print_header();
	for (int j=0; j<size; ++j) {
		/*
		printf("%02d: %10s | %6ld | %6.2f\n",
				arr_ptr[j]->id,
				arr_ptr[j]->line,
				arr_ptr[j]->size,
				arr_ptr[j]->flag);
		... same as ... */
		printf("%02d: %10s | %6ld | %6.2f\n",
				(*(arr_ptr + j))->id,
				(*(arr_ptr + j))->line,
				(*(arr_ptr + j))->size,
				(*(arr_ptr + j))->flag);
	}
}

/* coparison function for qsort -- line */
int cmpfunc_line(const void *a, const void *b) {
	Object_t *pA = *(Object_t **)a;
	Object_t *pB = *(Object_t **)b;

	/* case insensitive strings compare */
	return strcasecmp(pA->line, pB->line);
}

/* coparison function for qsort -- size */
int cmpfunc_size(const void *a, const void *b) {
	Object_t *pA = *(Object_t **)a;
	Object_t *pB = *(Object_t **)b;

	/* uint numbers compare: smallest to largest */
    return (pA->size - pB->size);
}
