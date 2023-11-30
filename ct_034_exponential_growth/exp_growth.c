#include <stdio.h>
#include <math.h>

/*
 * exponential growth --> eulers number:
 * A = (1 + 1/n)^n
 */
double calculate_exp_growth(long endn) {
	return pow((1.0 + 1.0/endn), endn);
}

int main(int argc, char **argv) {
	
	long long N = 1e8;

	for (long long i=1; i<N; i += 2*(N/100)) {
		printf("%-10lld%.30f\n", i, calculate_exp_growth(i)); 
	}

	return 0;
}
