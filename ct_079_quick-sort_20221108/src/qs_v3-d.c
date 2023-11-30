/* from:
 * Quicksort Algorithm Implementation | C Programming Example
 * https://www.youtube.com/watch?v=0jDiBM68NGU
 * 
 * channel: https://www.youtube.com/c/PortfolioCourses
 * original sc: https://github.com/portfoliocourses/c-example-code/blob/main/quicksort.c
 */

/* v3-d
 * accept values for ARR_LEN and MAX_INT as arguments to program
 * or demanded by main
 * display width set to 110 places (with trunover point dependant
 * on number of MAX_INT digits)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // v3-d


void line(int n);
void print_array(int arr[], size_t len, int d);
void swap(int *x, int *y);
void quicksort(int arr[], size_t len);
void quicksort_rec(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// main
int main(int argc, char **argv) {

	// v3-d
	int ARR_LEN;
	int MAX_INT;

	if (argc == 3) {
		ARR_LEN = atoi(argv[1]);
		MAX_INT = atoi(argv[2]);
	} else {
		printf("Array length: ");
		scanf("%d", &ARR_LEN);

		printf("Max intiger: ");
		scanf("%d", &MAX_INT);
	}

	// v3-d: number of digits for printf
	int dnum = log10(MAX_INT) + 1;

	srand(time(0));
	int arr[ARR_LEN];

	for (int i=0; i < ARR_LEN; i++) {
		arr[i] = rand() % MAX_INT;
	}

	printf("Unsorted array:\n");
	print_array(arr, ARR_LEN, dnum);
	line(3);

	printf("Sorted array:\n");
	quicksort(arr, ARR_LEN);
	print_array(arr, ARR_LEN, dnum);
	line(3);

	return 0;
} // end main

// function definitions

void line(int n) {
	for (int i=0; i < n; i++) {
		printf("-");
	}
	printf("\n");
}


void print_array(int arr[], size_t len, int d) {

	// v3-d: width of line
	int turnover = floor(110 / (d + 1));

	int count = 0;
	for (int j=0; j < len; j++) {
		if (++count % turnover == 0) {
			printf("%*d\n", d + 1, arr[j]);
		} else {
			printf("%*d", d + 1, arr[j]);
		}
	}
	printf("\n");
}



void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


void quicksort(int arr[], size_t len) {
	quicksort_rec(arr, 0, len - 1);
}


void quicksort_rec(int arr[], int low, int high) {
	if (low < high) {
		int pivot_idx = partition(arr, low, high);
		quicksort_rec(arr, low, pivot_idx - 1);
		quicksort_rec(arr, pivot_idx + 1, high);
	}
}

int partition(int arr[], int low, int high) {
	// v1-en
	// int pivot_value = arr[high];
	
	//v2-en pivot: random value between low and high
	// srand(time(0)); // already in main
	int pivot_idx = low + (rand() % (high - low));

	// test print
	// printf("pivot_idx: %d\n", pivot_idx);

	if(pivot_idx != high) {
		swap(&arr[pivot_idx], &arr[high]);
	}
	int pivot_value = arr[high];

	int i = low;

	for (int j=low; j < high; j++) {
		if (arr[j] <= pivot_value) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);

	return i; // that is where the pivot is
}

