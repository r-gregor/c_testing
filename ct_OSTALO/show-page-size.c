/* filename: ct_OSTALO/show-page-size.c
 * 20250518 mdb
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char **argv) {

	printf("Page size: %d\n", getpagesize());

	return 0;
}
