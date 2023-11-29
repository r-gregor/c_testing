/*
 * t3_mmap_test_v1.c
 * FROM: The Origins of Process Memory | Exploring the Use of Various Memory Allocators in Linux C
 *       Low Level Learning
 *       https://www.youtube.com/watch?v=c7xf5dvUb_Q
 *       1: runtime allocation: malloc
 *       2: sbrk/brk system call
 *    [!]3: mmap
 * 20230819 / 01 (en)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>

#define HOW_MUCH 0x1000   // 4096 bytes

intptr_t cpb;          // current program break
intptr_t curr_pos = 0;
intptr_t diff;
int elements = 0;

void clr();

/* MAIN */
void displayElement(int *arr, int pos);
int main(void) {

	clr();
	printf("t3: mmap test\n---\n");

	void *newMemory = mmap(NULL,
			HOW_MUCH,
			PROT_READ|PROT_WRITE,
			MAP_PRIVATE|MAP_ANONYMOUS,
			0, 0);

	if (NULL == newMemory) {
		perror("mmap: ");
		return -1;
	}

	printf("Current memory position: %p\n", sbrk(0));
	printf("Newly allocated memory:  %p (set by system, dest==NULL)\n", newMemory);

	int *myNewArray = (int *)newMemory;
	cpb = (intptr_t)myNewArray;

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

	munmap(newMemory, HOW_MUCH);


	return 0;
} // end MAIN


void displayElement(int *arr, int pos) {
	if (elements <= 0) {
		diff = (intptr_t)&arr[pos] - cpb;
	} else {
		diff = (intptr_t)&arr[pos] - curr_pos;
	}
	printf("value:%d, at address:     %p, position: %d, diff: %3ld bytes\n", arr[pos], &arr[pos], pos, diff);
	elements += 1;
	curr_pos = (intptr_t)&arr[pos];
}


/* clear the screen */
void clr() {
	system("@cls||clear");
}

