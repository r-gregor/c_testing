/*
 * filename: sizeofarray.c
 * 20260112 v1 en
 * 20260122 v2 en: remove unused 'get_nth_element()' function
 *                 update 'get_nth_element_str()' function
 *                 add 'show_nth_element()' function from v1 TODO:
 * last: 20260122
 */
#include <stdio.h>
#include <string.h>

typedef struct arrstrct arrstrct_t;

size_t get_arr_elnum(int *arr, size_t arr_size);
arrstrct_t new_arr(int *arr, size_t arr_size);
int get_nth_element_str(arrstrct_t *arrstri, size_t n);
void show_nth_element(arrstrct_t *arrstrct, size_t index);

struct arrstrct {
	int *arr;
	size_t count;
};

int main(int argc, char **argv) {

	int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nums2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300};

	/* by hand: BAD */
	arrstrct_t arr1;
	arr1.arr = nums1;
	arr1.count = get_arr_elnum(nums1, sizeof(nums1));

	/* by func: GOOD */
	arrstrct_t arr2 = new_arr(nums2, sizeof(nums2));

	/* how n-th element */
	show_nth_element(&arr1, 3);
	show_nth_element(&arr1, 11);
	show_nth_element(&arr2, 3);
	show_nth_element(&arr2, 11);

	return 0;
}

size_t get_arr_elnum(int *arr, size_t arr_size) {
	return arr_size/sizeof(arr[0]);
}

arrstrct_t new_arr(int *arr, size_t arr_size) {
	arrstrct_t newarr;
	newarr.arr = arr;
	newarr.count = arr_size/sizeof(arr[0]);
	return newarr;
}

int get_nth_element_str(arrstrct_t *arrstr, size_t n) {
	if (n <= 0 || n >= arrstr->count) {
		return -1;
	}
	return arrstr->arr[n - 1];
}

void show_nth_element(arrstrct_t *arrstrct, size_t index) {
	size_t el  = get_nth_element_str(arrstrct, index);
	size_t cnt = arrstrct->count;
	printf("There are %ld elements in an array.\n", cnt);
	if(el == -1) {
		printf("Index (%ld) must  be at least 1 and smaller as array size (%ld)!\n", index, cnt);
	} else {
		printf("%ld-th element of array: %ld\n", index, el);
	}
	printf("---\n");
}

