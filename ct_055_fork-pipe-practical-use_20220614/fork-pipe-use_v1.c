#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * split calculating the sum of an array into
 * calculating sum for each half of an array
 * in parallel by forking parent process into
 * another child process
 *
 */
int main(int argc, char **argv) {
	int arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	int fd[2];

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

	// will print sums from both processes: child and parrent
	// order is not defined, they run parallel
	printf("Calculated partial sum: %d\n", sum);

	// send sum from child to parent process
	// and calculate total sum from both processes
	if (id == 0) {
		// if in child process

		// close reading size of pipe
		// we dont need it
		close(fd[0]);

		// write to the end of the pipe of child process
		write(fd[1], &sum, sizeof(sum));

		// close writing size of pipe
		close(fd[1]);
	} else {
		// if in parent process

		// close writin side of pipe
		// not needed
		close(fd[1]);

		int totalSum = 0;
		int sumFromChild;
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		totalSum = sum + sumFromChild;
		printf("Total sum: %d\n", totalSum);

		// wait for child process to finish
		wait(NULL);
	}


	return 0;
}

