/* filename: ct_OSTALO/show-page-size.c
 * 20250518 mdb
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char **argv) {

	/* printf("Page size: %d\n", getpagesize()); // non POSIX */

	/* on WIN (cygwin) page size is: 65536 (64K) */
	printf("Size of memory page (_SC_PAGESIZE):  %d\n", sysconf(_SC_PAGESIZE));
	printf("Size of memory page (_SC_PAGE_SIZE): %d\n", sysconf(_SC_PAGE_SIZE));
	return 0;
}
