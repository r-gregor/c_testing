#include <stdio.h>
#include <math.h>

void pi_approx(long ninter) {
	double sum = 0.0;
	long cnt = 0;

	for (long i=1; i < (ninter*2); i += 2) {
		if (cnt == 0) {
			sum = 1.0/i;
		} else if ( (cnt % 2) == 0) {
			sum = sum + (1.0/i);
		} else {
			sum = sum - (1.0/i);
		}
		cnt += 1;
	} 
	printf("PI approx after %ld iterations: %.40f\n", ninter, (sum * 4));
	fflush(stdin);
}

int main() {
	
	printf("PI approximation --> PI/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...\n");

	for (int num=0; num < 100000001; num += 5000000) {
		pi_approx(num);
	}
	return 0;
}

/*
 * $> time ./infinite_sum.exe
 * PI approximation --> PI/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
 * PI approx after 0 iterations: 0.00000000000000000000
 * PI approx after 5000000 iterations: 3.14159245358977967655
 * ...
 * PI approx after 100000000 iterations: 3.14159264358932599492
 * 
 * real    0m4.682s
 * user    0m4.593s
 * sys     0m0.016s
 */
