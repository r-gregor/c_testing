/*
 * t2_sbrk_test_v1.c
 * FROM: The Origins of Process Memory | Exploring the Use of Various Memory Allocators in Linux C
 *       Low Level Learning
 *       https://www.youtube.com/watch?v=c7xf5dvUb_Q
 *       1: runtime allocation: malloc
 *    [!]2: sbrk/brk system call
 *       3: mmap
 * 20230819 / 01 (en)
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

	void *firstEnd = sbrk(0); // set program break at 0 offset from memory addres apointed by kernel
	cpb = (intptr_t)firstEnd;
	printf("Current Program Break: %p\n", firstEnd);

	void *currentEnd = sbrk(START);
	printf("New Program Break:     %p\n", currentEnd);
	curr_pos = (intptr_t)currentEnd;

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
	if (elements <= 0) {
		diff = (intptr_t)&arr[pos] - cpb;
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

