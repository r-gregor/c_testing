#include <stdio.h>
#include <string.h>

#define ARR_LEN(a) (sizeof(a)) / (sizeof((a)[0]))
#define MAX_STR_LEN 100

/*
 * works in both cases if no need to get
 * ARR_LEN() because in case of cahr * String
 * the length is the len of char poinetr not array
 */
//typedef char String[MAX_STR_LEN];
typedef char * String;

void iprintOut(int a[], int n);
void sprintOut(char a[], int n);
void sprintOutNoCommas(char a[]);
void sprintOutString(String s);


// main
int main(int argc, char **argv) {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char nm[] = {'G', 'r', 'e', 'g', 'o', 'r', ' ', 'R', 'e', 'd', 'e', 'l', 'o', 'n', 'g', 'h', 'i', '\0'};
	String mywife = "Tadeja Mali Redelonghi";

	iprintOut(a, ARR_LEN(a));
	sprintOut(nm, ARR_LEN(nm));
	sprintOutNoCommas(nm);
	sprintOutString(mywife);

	return 0;
} // end main


/*
 * printi out an array of ints
 */
void iprintOut(int a[], int n) {
	printf("Printed as int array: ");
	int *last = a + n - 1;
	for ( ; a < last ; a++) {
		printf("%d, ", *a);
	}
	printf("%d\n", *last);
}

/*
 * print out char array or string
 */
void sprintOut(char a[], int n) {
	printf("Printed as char array: ");
	char *last = a + n - 2;         // last = -1 + (-1) for null character
	for ( ; a < last ; a++) {
		printf("%c, ", *a);
	}
	printf("%c\n", *last);
}

/*
 * print out char array or string
 * with no commas between chars
 * no need for int n (ARR_LEN)
 */
void sprintOutNoCommas(char a[]) {
	int pos = 0;
	printf("Printed as char array: ");
	while( *(a + pos) != '\0') {
		printf("%c", *(a + pos));
		pos++;
	}
	printf("\n");
}

/*
 * print out char array or string
 * with no commas between chars
 * no need for int n (ARR_LEN)
 */
void sprintOutString(String s) {
	int pos = 0;
	printf("Printed as String type: ");
	while( *(s + pos) != '\0') {
		printf("%c", *(s + pos));
		pos++;
	}
	printf("\n");
}

