/* from:
 * Quicksort Algorithm Implementation | C Programming Example
 * https://www.youtube.com/watch?v=0jDiBM68NGU
 * 
 * channel: https://www.youtube.com/c/PortfolioCourses
 * original sc: https://github.com/portfoliocourses/c-example-code/blob/main/quicksort.c
 */

/* v2-en
 * pivot point: random array element!
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 300
#define MAX_INT 300

void line(int n);
void print_array(int arr[], size_t len);
void swap(int *x, int *y);
void quicksort(int arr[], size_t len);
void quicksort_rec(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// main
int main(int argc, char **argv) {
	srand(time(0));
	int arr[ARR_LEN];

	for (int i=0; i < ARR_LEN; i++) {
		arr[i] = rand() % MAX_INT;
	}

	printf("Unsorted array:\n");
	print_array(arr, ARR_LEN);
	line(3);

	printf("Sorted array:\n");
	quicksort(arr, ARR_LEN);
	print_array(arr, ARR_LEN);
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


void print_array(int arr[], size_t len) {
	int count = 0;
	for (int j=0; j < len; j++) {
		if (++count % 30 == 0) {
			printf("%4d\n", arr[j]);
		} else {
			printf("%4d", arr[j]);
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


