#include <stdio.h>

int main() {

	printf("Hello World!\n");
	
	int arr[5] = {10, 20 ,30, 40, 50};
	int *ptr1 = arr; // &arr[0]

	// first loop type:
	for (int i=0; i<5; i++) {
		printf("%d ",  arr[i]);
	}
	printf("\n");

	printf("ptr1: %d\n", *ptr1);
	printf("\n");


	// second loop type:
	for (int i=0; i<5; i++) {
		printf("%d ",  ptr1[i]);
	}
	printf("\n");


	printf("\n");
	return 0;
}
