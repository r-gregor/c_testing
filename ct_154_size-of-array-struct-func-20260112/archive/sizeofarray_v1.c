/*
 * filename: sizeofarray_v1.c
 * 20260112 v1 en
 * last: 20260112
 */
#include <stdio.h>
#include <string.h>

typedef struct arrstrc arrstrc_t;

size_t get_arr_elnum(int *arr, size_t arr_size);
arrstrc_t new_arr(int *arr, size_t arr_size);
int get_nth_element(int *arr, int n);
int get_nth_element_str(arrstrc_t *arrstri, size_t n);

struct arrstrc {
	int *arr;
	size_t count;
};

int main(int argc, char **argv) {

	int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nums2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300};

	/* by hand: BAD */
	arrstrc_t arr1;
	arr1.arr = nums1;
	arr1.count = get_arr_elnum(nums1, sizeof(nums1));

	/* by func: GOOD */
	arrstrc_t arr2 = new_arr(nums2, sizeof(nums2));

	/* TODO: display n-th element function */
	printf("arr1 has %ld elements\n", arr1.count);
	printf("arr2 has %ld elements\n", arr2.count);

	printf("3-th element of arr1: %d\n", get_nth_element(arr1.arr, 3));
	printf("11-th element of arr2: %d\n", get_nth_element(arr2.arr, 11));

	printf("11-th element of arr2: %d\n", get_nth_element_str(&arr2, 11));
	printf("11-th element of arr2: %d\n", get_nth_element_str(&arr2, 14));

	return 0;
}

size_t get_arr_elnum(int *arr, size_t arr_size) {
	return arr_size/sizeof(arr[0]);
}

arrstrc_t new_arr(int *arr, size_t arr_size) {
	arrstrc_t newarr;
	newarr.arr = arr;
	newarr.count = arr_size/sizeof(arr[0]);
	return newarr;
}


int get_nth_element(int *arr, int n) {
	if (n <= 0) {
		printf("Index must be al least 1!\n");
		return -1;
	}
	return arr[n - 1];
}

int get_nth_element_str(arrstrc_t *arrstr, size_t n) {
	if (n <= 0 || n >= arrstr->count) {
		printf("Index must be at least 1 and smaller as array size!\n");
		return -1;
	}
	return arrstr->arr[n - 1];
}

