#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* An array of pointers to structs with fixed length strings
 * elements and two sort functions to sort by date string forward
 * and reverse. 
 */

typedef struct f_name {
	char date[9];
	char fname[255];
}Fname;

int *fcount;                                    // declare global pointer
Fname **fname_arr;                              // declare array of poinetrs to struct Fname
void printArr(Fname **, int *);                 // declare func to print an array
int sort_date(const void*, const void *);       // declare forward sort by date func
int sort_date_rev(const void*, const void *);   // declare reverse sort by date func

/* main */
int main(int argc, char **argv) {

	fcount = malloc(sizeof(int));               // reseve memory for global counter
	*fcount = 0;                                // initialize global counter

	fname_arr = malloc(sizeof(Fname *) * 5);    // reserve memory for array of 5 poinetrs to struct Fname

	fname_arr[0] = malloc(sizeof(Fname));       // reserve memory for a Fname struct pointer
	strcpy(fname_arr[0]->date, "20210101");
	strcpy(fname_arr[0]->fname, "/home/rgregor/files/file_20210101.txt");
	(*fcount)++;

	fname_arr[1] = malloc(sizeof(Fname));
	strcpy(fname_arr[1]->date, "19680222");
	strcpy(fname_arr[1]->fname, "/home/rgregor/files/file_19680222.txt");
	(*fcount)++;

	fname_arr[2] = malloc(sizeof(Fname));
	strcpy(fname_arr[2]->date, "20220222");
	strcpy(fname_arr[2]->fname, "/home/rgregor/files/file_20220222.txt");
	(*fcount)++;

	fname_arr[3] = malloc(sizeof(Fname));
	strcpy(fname_arr[3]->date, "20080211");
	strcpy(fname_arr[3]->fname, "/home/rgregor/files/very.long-file_20080211.txt");
	(*fcount)++;

	fname_arr[4] = malloc(sizeof(Fname));
	strcpy(fname_arr[4]->date, "20300101");
	strcpy(fname_arr[4]->fname, "/home/rgregor/files/newest-file_20300101.txt");
	(*fcount)++;

	printf("-----------------------------\nBefore sort:\n");
	printArr(fname_arr, fcount);

	printf("-----------------------------\nAfter sort:\n");
	qsort(fname_arr, *fcount, sizeof(Fname *), sort_date);
	printArr(fname_arr, fcount);

	printf("-----------------------------\nAfter REVERSE sort:\n");
	qsort(fname_arr, *fcount, sizeof(Fname *), sort_date_rev);
	printArr(fname_arr, fcount);
	return 0;
} // end main


void printArr(Fname **arr, int *count) {
	for (int i=0; i < *count; i++) {
		printf("%-12s%s\n", arr[i]->date, arr[i]->fname);
	}
}

int sort_date(const void* a, const void *b) {
	Fname *f1 = *(Fname **)a;
	Fname *f2 = *(Fname **)b;
	return strcmp(f1->date, f2->date);
}

int sort_date_rev(const void* a, const void *b) {
	Fname *f1 = *(Fname **)a;
	Fname *f2 = *(Fname **)b;
	return strcmp(f2->date, f1->date);
}

