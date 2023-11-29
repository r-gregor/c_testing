#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

void displayArray(int [], int);

/**
 * split calculating the sum of an array into
 * calculating sum for each half of an array
 * in parallel by forking parent process into
 * another child process
 *
 * v2 - print statements in each process
 *    - error cheking for read() and write() functions
 *
 * v3 - display contents of an array
 */
int main(int argc, char **argv) {
	int arr[] = {1, 2, 3, 4, 5, 1, 2, 7, 7, 8, 9};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	int fd[2];

	displayArray(arr, arrSize);

	// open a pipe and check if it failed
	if (pipe(fd) == -1) {
		fprintf(stderr, "Piping failed!\n");
		return 1;
	}

	// start a fork process and check if it failed
	int id = fork();
	if (id == -1) {
		fprintf(stderr, "Forking failed!\n");
		return 2;
	}

	// set start and end position of partial sums
	if (id == 0) {
		// if it is a CHILD process
		// floor of first half of the array
		// from 0 till arrSize / 2
		start = 0;
		end = arrSize / 2;
	} else {
		// if it is a parent process
		// from arrSize till the end of the array
		start = arrSize / 2;
		end = arrSize;
	}


	// calculating the sum
	int sum = 0;
	int i;

	for (i = start; i < end; i++) {
		sum += arr[i];
	}

	// send sum from child to parent process
	// and calculate total sum from both processes
	if (id == 0) {
		// if in child process

		// v2
		printf("Sum in a CHILD process from index %d to %d: %d\n", start, end - 1, sum);
	
		// close reading size of pipe
		// we dont need it
		close(fd[0]);

		// write to the end of the pipe of child process
		// v2
		if (write(fd[1], &sum, sizeof(sum)) == -1) {
			fprintf(stderr, "Could'n write!\n");
			return 4;
		}

		// close writing size of pipe
		close(fd[1]);
	} else {
		// if in parent process
		
		// v2
		printf("Sum in a PARENT process from index %d to %d: %d\n", start, end - 1, sum);

		// close writin side of pipe
		// not needed
		close(fd[1]);

		int totalSum = 0;
		int sumFromChild;

		// v2
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1) {
			fprintf(stderr, "Could'n read!\n");
			return 5;
		}

		close(fd[0]);

		totalSum = sum + sumFromChild;
		printf("Total sum: %d\n", totalSum);

		// wait for child process to finish
		wait(NULL);
	}


	return 0;
}

void displayArray(int array[], int size) {
	int j;
	printf("Array = [");
	for (j=0; j < size - 1; j++) {
		printf("%d, ", array[j]);
	}
	printf("%d", array[size - 1]);
	printf("]\n");
}

