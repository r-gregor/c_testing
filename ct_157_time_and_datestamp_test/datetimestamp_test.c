/*
 * fname: datetimestamp_test.c
 * 20260310 en v1
 * last: 20260310
 */
#include <stdio.h>
#include <string.h>
#include "datestamp.h"
#include "timestamp.h"

/* main */
int main(int argc, char **argv) {

	printf("Datestamp: (%s)\n", get_datestamp());
	printf("Timestamp: (%s)\n", get_timestamp());

	printf("\n");
	return 0;
} /* end main */

