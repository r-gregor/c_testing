/* uconcat.c
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 *       at 01:25:35 / 04:01:25
 * ---
  20231115_01 (en)
  20240524_02 (en) v5: all interfaces in single header file: ubuild.h
 */
#include <assert.h>
#include "ubuild.h"
#define HL3 printf("---\n");

int main(void) {
	printf("Trying to concatenate \"foo\" and \".c\" ...\n");
	assert(strcmp("foo.c", CONCAT("foo", ".c")) == 0);
	printf("Concatenated string:  \"%s\"\n", CONCAT("foo", ".c"));

	return 0;
}

