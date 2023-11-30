#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArrS(char **, size_t);
void printArrI(long [], size_t);

int cmpr_i(const void *s1, const void *s2) {
	long date1 = *(long *)s1;
	long date2 = *(long *)s2;
	return date2 - date1;
}

int cmpr_s(const void *s1, const void *s2) {
	char *string1 = *(char **)s1;
	char *string2 = *(char **)s2;
	return strcasecmp(string2, string1);
}

int main(int argc, char **argv) {

	// char *names[] = {"Zala", "Spela", "Antonija", "Mark", "Gregor"};
	// char *names[] = {"20080211", "19000101", "20220222", "19680222", "19700119"};
	char *names[] = {"gregor123456", "jadajaja222222", "Zandaja", "2222244444","ALmanahaaa", "22222244", "123456_kjvkv"};
	long datums[] = {20080211, 19000101, 20220222, 19680222, 19700119};
	size_t numi = sizeof(datums) / sizeof(datums[0]);
	size_t nums = sizeof(names) / sizeof(names[0]);

	printf("Before sort:\n");
	printArrI(datums, numi);
	printArrS(names, nums);

	printf("\n=========================\nAFTER sort:\n");
	qsort(datums, numi, sizeof(datums[0]), cmpr_i);
	qsort(names, nums, sizeof(names[0]), cmpr_s);
	printArrI(datums, numi);
	printArrS(names, nums);

	return 0;
}

void printArrS(char **arr, size_t size) {
	printf("--------------------------\n");
	for (int i=0; i<size; i++) {
		printf("%s\n", arr[i]);
	}
}

void printArrI(long arr[], size_t size) {
	printf("--------------------------\n");
	for (int i=0; i<size; i++) {
		printf("%ld\n", arr[i]);
	}
}

