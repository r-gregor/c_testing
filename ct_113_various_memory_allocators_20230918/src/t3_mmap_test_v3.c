/*
 * t3_sbrk_test_v3.c
 * FROM: The Origins of Process Memory | Exploring the Use of Various Memory Allocators in Linux C
 *       Low Level Learning
 *       https://www.youtube.com/watch?v=c7xf5dvUb_Q
 *       1: runtime allocation: malloc
 *    [!]2: sbrk/brk system call
 *       3: mmap
 * 20230819 / 01 (en)
 * 20230819 / 02 (d)
 * 20230819 / 03 (d)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define START 0x1000   // 4096 bytes

intptr_t cpb;          // current program break
intptr_t curr_pos = 0;
intptr_t diff;
int elements = 0;

void displayElement(int *arr, int pos);
void clr();

/* MAIN */
int main(void) {

	clr();
	printf("t2: sbrk/brk test\n---\n");

	void *firstEnd = sbrk(0);    // get current program break memory point
	cpb = (intptr_t)firstEnd;
	printf("Current Program Break: %18p\n", firstEnd);

	// sbrk(START);
	if(!sbrk(START)) {           // returns previous program break [**1]
		fprintf(stderr, "Could not allocate memory\n");
	}
	void *currentEnd = sbrk(0);  // because of [**1]: new current program brak
	printf("New Program Break:     %18p\n", currentEnd);
	curr_pos = (intptr_t)currentEnd;

	size_t diff2 = currentEnd - firstEnd;
	printf("-----------------------------------------\n");
	char output[80];
	sprintf(output, "(%ld bytes) %lx\n", diff2, diff2);
	printf("diff:                   %s", output);

	printf("---\n");

	int *myNewArray = (int *)firstEnd;

	myNewArray[100] = 2;
	myNewArray[101] = 3;
	myNewArray[103] = 4;
	myNewArray[108] = 5;
	myNewArray[109] = 1;
	myNewArray[111] = 9;

	displayElement(myNewArray, 100);
	displayElement(myNewArray, 101);
	displayElement(myNewArray, 103);
	displayElement(myNewArray, 108);
	displayElement(myNewArray, 109);
	displayElement(myNewArray, 111);

	return 0;
} // end MAIN


void displayElement(int *arr, int pos) {
	// first element: diff to initial memory position
	if (elements <= 0) {
		diff = (intptr_t)&arr[pos] - cpb;
	// other elements: diff to previous element
	} else {
		diff = (intptr_t)&arr[pos] - curr_pos;
	}
	printf("value:%d, at address:   %p, position: %d, diff: %3ld bytes\n", arr[pos], &arr[pos], pos, diff);
	elements += 1;
	curr_pos = (intptr_t)&arr[pos];
}

/* clear the screen */
void clr() {
	system("@cls||clear");
}

