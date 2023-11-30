/*
 * integer_division_using_div_v1.c
 * integer division using div() function that returns sruct
 * holding info about quotient and remainder
 * 20230901 (en)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    // srand()

void integer_division(int dividend, int divisor);
void rand_integer_division();
void swap_int(int *a, int *b);
void crt(int n);


/* MAIN */
int main(int argc, char **argv) {

	printf("\n--- Integer divisions using div() ---\n");
	/*
	 * Dividend = Divisor × Quotient + Remainder
	 * Dividend/Divisor = Quotient
	 * Dividend = Divisor × Quotient
	 */
	integer_division(45, 33);
	integer_division(0, 33);
	integer_division(12, 33);
	integer_division(1200, 60);
	integer_division(6200, 1250);
	integer_division(-45, 33);
	integer_division(-12, 33);
	
	printf("\n--- Random Integer divisions using div() ---\n");
	srand(time(0));
	int stop = 5;
	while (stop >= 0) {
		rand_integer_division();
		stop--;
	}

	crt(3);

	return 0;
} // end MAIN


/*
 * Dividend = Divisor × Quotient + Remainder
 * Dividend/Divisor = Quotient
 * Dividend = Divisor × Quotient
 */

/*
 * prints expression describing integer division of integers
 * with quotient + reminder as result
 * it performs division only if dividend and divisor are not 0 (do_division flag)
 */
void integer_division(int dividend, int divisor) {

	/* good to go */
	int do_division = 1;

	if (dividend == 0 || divisor == 0) {
		printf("%5d / %-5d = ", dividend, divisor);
		printf("    *** Dividend or divisor cannot be zero! ***\n");

		/* skip */
		do_division = 0;
	}

	if (abs(dividend) < abs(divisor)) {
		swap_int(&dividend, &divisor);
	}

	if (do_division) {
		div_t result = div(dividend, divisor);
		printf("%5d / %-5d = %5d * %-5d + %d\n", dividend, divisor, result.quot, divisor, result.rem);
	}
}

/*
 * prints expression describing integer division of random integers between -998 and 9999
 * with quotient + reminder as result
 * it performs division only if dividend and divisor are not 0 (do_division flag)
 */
void rand_integer_division() {

	int dividend = rand() % 9999 - 998;
	int divisor = rand() % 9999 - 998;

	/* good to go */
	int do_division = 1;

	if (dividend == 0 || divisor == 0) {
		printf("%5d / %-5d = ", dividend, divisor);
		printf("    *** Dividend or divisor cannot be zero! ***\n");

		/* skip division */
		do_division = 0;
	}

	if (abs(dividend) < abs(divisor)) {
		swap_int(&dividend, &divisor);
	}

	/* if good to go */
	if (do_division) {
		div_t result = div(dividend, divisor);
		printf("%5d / %-5d = %5d * %-5d + %d\n", dividend, divisor, result.quot, divisor, result.rem);
	}
}

/* swap values of two integers parameters */
void swap_int(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* h-line */
void crt(int n) {
	for (int i=0; i < n; i++) {
		printf("-");
	}
	printf("\n");
}

