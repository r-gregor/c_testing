#include <stdio.h>

void nwl(int n) {
	if (n <= 1) {
		printf("\n");
	} else {
		for (int i = 0; i < n; i++) {
			printf("\n");
		}
	}
}

int main() {

	int arr[5] = {1000, 2000 ,3000, 4000, 5000};

	printf("Memmory location of the first and the last element of an array:\n");
	printf("First: %d\nLast: %d\n", &arr[0], &arr[4]);
	printf("Number of elements in an array: %ld", sizeof(arr)/sizeof(arr[0]));


	// iterate over elemnts af an array using pointers
	//
	nwl(1);
	int *p;
	printf("Size in bytes of int pointer: %ld\n", sizeof(*p));
	printf("Size in bytes of int pointer: %ld\n", sizeof(int));

	nwl(1);
	printf("Is sizeof(*p) == sizeof(int) \"True\" or \"False\"? ");
	printf("%s\n", sizeof(*p) == sizeof(int) ? "True" : "False");

	nwl(1);
	printf("Elements of an array:\n");
	// p++ = p + 1 * (sizeof(type of the pointer))
	for (p=&arr[0]; p <= &arr[4]; p++) {
		printf("%d ", *p);
	}

	nwl(2);
	printf("Memmory locations of the elements of an array:\n");
	// p++ = p + 1 * (sizeof(type of the pointer))
	for (p=&arr[0]; p <= &arr[4]; p++) {
		printf("%d ", p);
	}
	nwl(2);


	return 0;
}
