#include <stdio.h>
#include <string.h>

typedef struct {
	int num;
	char wnum[32];
} Nums;

void disp_arr(Nums *array, int arr_len);
void disp_arr_rev1(Nums *array, int arr_len);
void disp_arr_rev2(Nums *array, int arr_len);

/**
 * MAIN
 */
int main(int argc, char **argv) {

Nums arr[] = {
	{1, "ONE"},
	{2, "TWO"},
	{3, "THREE"},
	{4, "FOUR"},
	{5, "FIVE"},
	{6, "SIX"},
	{7, "SEVEN"},
	{8, "EIGHT"},
	{9, "NINE"},
	{10, "TEN"}
};

	int arr_len = sizeof(arr)/sizeof(Nums);
	Nums *item;

#if 1
	printf("Displaying array with for loop directly:\n");
	item = arr;
	for (int i = 0; i < arr_len - 1; ++i) {
		printf("%5d, ", item->num);
		item++;
	}
	printf("%5d\n", item->num);

	item = arr;
	for (int i = 0; i < arr_len - 1; ++i) {
		printf("%5s, ", item->wnum);
		item++;
	}
	printf("%5s\n", item->wnum);

	printf("---\n");
#endif

	// first loop
	disp_arr(arr, arr_len);
	printf("---\n");

	// second loop
	disp_arr_rev1(arr, arr_len);
	printf("---\n");

	// third loop
	disp_arr_rev2(arr, arr_len);

	return 0;
} // end MAIN

/** FIRST func */
void disp_arr(Nums *array, int arr_len) {
	Nums *item;
	printf("disp_arr() func: displaying array with for loop:\n");
	item = array;
	for (int i = 0; i < arr_len - 1; ++i) {
		printf("%5d, ", item->num);
		item++;
	}
	printf("%5d\n", item->num);
	// ---
	item = array;
	for (int i = 0; i < arr_len - 1; ++i) {
		printf("%5s, ", item->wnum);
		item++;
	}
	printf("%5s\n", item->wnum);
}

/** SECOND func */
void disp_arr_rev1(Nums *array, int arr_len) {
	printf("disp_arr_rev1() func: displaying array with while loop - reversed:\n");
	Nums *item;
	int count;

	count = 0;
	item = array;
	while (count < arr_len - 1)   {
		printf("%5d, ", (item + arr_len - 1 - count)->num);
		count++;
	}
	printf("%5d\n", (item + arr_len - 1 - count)->num);
	// ---
	count = 0;
	item = array;
	while (count < arr_len - 1)   {
		printf("%5s, ", (item + arr_len - 1 - count)->wnum);
		count++;
	}
	printf("%5s\n", (item + arr_len - 1 - count)->wnum);
}

/** THIRD func */
void disp_arr_rev2(Nums *array, int arr_len) {
	printf("disp_arr_rev2() func: displaying array with while loop - reversed:\n");
	Nums *item;
	int len;

	item = array;
	len = arr_len;
	while (len > 1) {
		printf("%5d, ", (item + --len)->num);
	}
	printf("%5d\n", (item + --len)->num);
	// ---
	item = array;
	len = arr_len;
	while (len > 1) {
		printf("%5s, ", (item + --len)->wnum);
	}
	printf("%5s\n", (item + --len)->wnum);
}

