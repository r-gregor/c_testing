#include <stdio.h>
#include <string.h>
#include <math.h>

long double sum_pi(long int);

int main(int argc, char **argv) {

	long int iterations = 1e8;
	printf("Calculating PI using formulae: (PI^2)/6 = 1 + 1/2^2 + 1/3^2 + 1/4^2 + ... (%ld iterations)\n", iterations);
	printf("%.50Lf\n", (long double) sqrt(sum_pi(iterations) * 6));
	printf("3.14159265358979323846264338327950288419716939937510 <-- from wikipedia (PI to 50-eth decimal place)\n");


	return 0;
}

long double sum_pi(long int num) {
	long double sum = 1.0;
	long int i;

	for (i=2; i < num; i++) {
		sum += 1/(pow(i,2));
	}
	return sum;
 }

