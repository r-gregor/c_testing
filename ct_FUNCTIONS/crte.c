/* =================================================
 *
 * 1-st:
 * write "-" NLINES-times
 *
 */
#define NLINES 36

void crta(int n) {
	while(n != 0) {
		printf("-");
		n--;
	}
	printf("\n");
}

/*
 * run:
 * crta(NLINES);
 *
 */

/* =================================================
 *
 * 2-nd:
 * write "-" defined times
 *
 */

#define NUM_LINE_CHARS 80


void crta() {
	for (int i=0; i < NUM_LINE_CHARS; i++) {
		printf("-");
	}
	printf("\n");
}


/*
 * run:
 * crta();
 */


