#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define NUM_OF_NUMS 10

/*
 * testing getpid() function
 */

pid_t  curr_pid;
int    rand_num;
void random_num();

int main(int argc, char **argv) {

	for (int i = 0; i < NUM_OF_NUMS + 1; i++) {
		sleep(1);
		random_num();
	}

	return 0;
}

void random_num() {
	curr_pid = getpid();
	srand(time(NULL) * curr_pid);
	printf("PID: %d\trandom number: %d\n", curr_pid, rand());
}

