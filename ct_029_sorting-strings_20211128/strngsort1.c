#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_CHARS 256


int compare_str(const void *str1, const void *str2) {
	// return strcmp(str1, str2);
	return strcasecmp(str1, str2);
}

void print_array(char arr[][MAX_LINE_CHARS], int size) {
	for (int i=0; i < size; i++) {
		printf("%s\n", arr[i]);
	}
}

int main() {

	char paths[][MAX_LINE_CHARS] = {
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

	int n = sizeof(paths) / MAX_LINE_CHARS;

	printf("=== Array of paths before sorting ===\n");
	print_array(paths, n);
	printf("\n");

	printf("=== Array of paths AFTER sorting ===\n");
	qsort(paths, n, MAX_LINE_CHARS, compare_str);
	print_array(paths, n);

	return 0;
}

