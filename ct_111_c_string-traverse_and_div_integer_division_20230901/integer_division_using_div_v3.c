/*
 * integer_division_using_div_v3.c
 * integer division using div() function that returns sruct
 * holding info about quotient and remainder
 * 20230906 (en)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    // srand()

void rand_integer_division(unsigned int range);
void swap_int(int *a, int *b);
void crt(int n);
void usage(char *cmd);
void clr();


/* MAIN */
int main(int argc, char **argv) {

	if (argc != 2) {
		usage(argv[0]);
		return 1;
	}

	unsigned int range = atoi(argv[1]);
	if (range == 0) {
		fprintf(stderr, "Range cannot be '0'\n");
		return 2;
	}

	if (range > 9999) {
		usage(argv[0]);
		return 3;
	}

	/*
	 * Dividend = Divisor × Quotient + Remainder
	 * Dividend/Divisor = Quotient
	 * Dividend = Divisor × Quotient
	 */

	clr();
	printf("--- Random integer division of integers between %d and -%d ---\n",range, range);
	srand(time(0));
	int stop = 15;
	while (stop >= 0) {
		rand_integer_division(range);
		stop--;
	}

	crt(3);

	return 0;
} // end MAIN


/*
 * LOGIC:
 * Dividend = Divisor × Quotient + Remainder
 * Dividend/Divisor = Quotient
 * Dividend = Divisor × Quotient
 */

/*
 * prints expression describing integer division of random integers between -998 and 9999
 * with quotient + reminder as result
 * it performs division only if dividend and divisor are not 0 (do_division flag)
 */
void rand_integer_division(unsigned int range) {

	/* division between -9999 and 9999: (2*n) - n; n=9999 -- excluding 0 */
	unsigned int n = range;
	int dividend = rand() % (n * 2) - n;
	int divisor = rand() % (n * 2) - n;

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

void usage(char *cmd) {
	printf("Usage: %s [n (int)]\n", cmd);
	printf("\t\tn ... integer between 1 and 9999\n\n");
}

/* clear the screen */
void clr() {
	system("@cls||clear");
}

