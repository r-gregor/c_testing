#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_str2(const void *a, const void *b) {
    const char **pa,**pb;

    pa = (const char **)a;
    pb = (const char **)b;
    // return( strcmp(*pa,*pb) );
    return( strcasecmp(*pa,*pb) );
}

void print_array2(char **arr, int size) {
	for (int i=0; i < size; i++) {
		printf("%s\n", *arr);
		arr++;
	}
}

int main() {

	char *paths[] = {
		"/slike/Slika_1.jpg",
		"/home/rgregor/majstaf/coding",
		"/home/tadeja/Desktop",
		"/home/rgregor/majstaf/majmedia/Movies",
		"/SLIKE/danes",
		"/usr/local/bin",
		"/etc",
		"/",
		"/usr",
		"/home/tadeja",
		"/home",
		"/slike",
		"/home/rgregor"};

	int n = sizeof(paths) / sizeof(char *);
	printf("Number of elemnts in the array: %d\n", n);

	printf("=== Array of paths before sorting ===\n");
	print_array2(paths, n);
	printf("\n");


	printf("=== Array of paths AFTER sorting ===\n");
	qsort(paths, n, sizeof(char *), compare_str2);
	print_array2(paths, n);

	return 0;
}
