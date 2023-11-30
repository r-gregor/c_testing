/*
 * ubuild.c / v1
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 *       at 01:01:35 / 04:01:25
 * ---
 * 20231113_01 (en)
 * 20231113_02 (d)
 */
#include "ubuild.h"

int main(void) {

	printf("%s\n", PATH("foo", "bar", "baz", "test"));
	printf("%s\n", PATH("root", "home", "rgregor", "test"));


	return 0;
}
