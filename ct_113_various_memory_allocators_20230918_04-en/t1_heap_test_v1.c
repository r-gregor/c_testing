/*
 * t1_heap_test_v1.c
 * FROM: The Origins of Process Memory | Exploring the Use of Various Memory Allocators in Linux C
 *       Low Level Learning
 *       https://www.youtube.com/watch?v=c7xf5dvUb_Q
 *    [!]1: runtime allocation: malloc
 *       2: sbrk/brk system call
 *       3: mmap
 * 20230819 / 01 (en)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START 1024

void clr();

/* MAIN */
int main(void) {

	char *myHeap = malloc(START);
	if (NULL != myHeap) {
		strcpy(myHeap, "Hey There, memory!\n");
	}

	clr();
	printf("t1: heap test\n---\n");

	printf("%s", myHeap);
	printf("Address of myHeap: %p\n", myHeap);

	free(myHeap);

	return 0;
} // end MAIN


/* clear the screen */
void clr() {
	system("@cls||clear");
}

