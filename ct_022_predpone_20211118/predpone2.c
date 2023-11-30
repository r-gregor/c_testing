#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

	char prfxes[9] = {' ', 'K', 'M', 'G', 'T', 'P', 'X', 'Z', 'Y'};
	char *prfxnames[9] = {" ", "Kilo", "Mega", "Giga", "Tera", "Peta", "Exa", "Zetta", "Yotta"};

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <num [long]>\n", argv[0]);
		exit(1);
	}

	div_t divs;    /* div() functipn of type div_t returns struct with quot and rem elements */
	               /* div(int a, int b) ==> struct divs{quot, rem} */
	               /*     quot --> quotient (a // b) */
	               /*      rem --> remainder (a % b) */

	double num;
	num = atof(argv[1]);  /* convert command line argument to double */

	if (num >= 1e27) {
		fprintf(stderr, "Number larger as 10^28. Not able to display!\n");
		exit(2);
	}
	
	double exp = log10(num);                  /* base(10) logarithm of num: how many power-s of 10 */
	divs = div((int)exp, 3);                  /* struct divs ==> quot, rem */
	int prfxsnum = divs.quot;                 /* int of how many 1000-s: index to prfxes and prfxnames */
	double base = num / pow(1000,prfxsnum);   /* base: num reduced to less than 1000 */
	char prefix = prfxes[prfxsnum];           /* letter that represents prefix multiplier */

/*  TEST PRINTS
 * 	printf("Log of %f: %.2lf\n", num, exp);
 * 	printf("prfxsnum: %d\n", prfxsnum);
 * 	printf("base: %f\n", base);
 * 	printf("prefix: %c\n", prefix);
 */

	printf("Result: %.2f%c (%s)\n", base, prefix, prfxnames[prfxsnum]);

	return 0;
}

/*
 * Kilo, mega, giga, tera, peta, exa, zetta are among the list of binary prefixes used to denote the quantity
 * of something, such as a byte or bit in computing and telecommunications. Sometimes called prefix
 * multipliers, these prefixes are also used in electronics and physics. Each multiplier consists of a
 * one-letter abbreviation and the prefix it stands for.
 *
 * In communications, electronics and physics, multipliers are defined in powers of 10, from 10-24 to 1024,
 * proceeding in increments of three orders of magnitude -- 103 or 1,000. In IT and data storage, multipliers
 * are defined in powers of two, from 210 to 280, proceeding in
 * increments of 10 orders of magnitude -- 210 or 1,024.
 */
 
