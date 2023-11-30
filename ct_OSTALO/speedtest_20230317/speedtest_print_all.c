#include <stdio.h>
#include <string.h>

#define NUM_OF_ITERATIONS 1000000
#define EVERY_NTH 100

void display_sum_of_ints(int);
void display_every_nth_sum_of_ints(int);
void get_sum_of_int(int);

int main(int argc, char **argv) {

	// display_sum_of_ints(NUM_OF_ITERATIONS);
	display_every_nth_sum_of_ints(NUM_OF_ITERATIONS);
	// get_sum_of_int(NUM_OF_ITERATIONS);

	return 0;
}


void display_sum_of_ints(int num1) {
	unsigned int sum1 = 0;
	int i;
	for (i = 0; i < num1; i++) {
		printf("sum1 after %10d iterations: %u\n", i, sum1++);
	}
	printf("sum1 after %10d iterations: %u\n", i, sum1);
}

void display_every_nth_sum_of_ints(int num1) {
	unsigned int sum1 = 0;
	int i;
	for (i = 0; i < num1; i++) {
		if (i % EVERY_NTH == 0) {
			printf("sum1 after %10d iterations: %u\n", i, sum1++);
		} else {
			sum1++;
		}
	}
	printf("sum1 after %10d iterations: %u\n", i, sum1);
}

void get_sum_of_int(int num2) {
	unsigned int sum2 = 0;
	int j;
	for (j = 0; j < num2; j++) {
		sum2++;
	}
	printf("sum2 after %10d iterations: %u\n", j, sum2);
}

