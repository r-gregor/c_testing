/* ubuild.c / v3
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 *       v1 at 01:01:35 / 04:01:25
 *       v2 at 01:18:49 / 04:01:25
 * ---
 * 20231113_01 (en)
 * 20231113_02 (d)
 * 20231114_03 (en)
 * 20231115_04 (en)
 */
#include "ubuild.h"
#define HL3 printf("---\n");

int main(void) {

	printf("%s\n", PATH("foo", "bar", "baz", "test"));
	printf("%s\n", PATH("RUUT", "home", "rgregor", "tests"));
	HL3

	MKDIRS("RUUT", "home", "rgregor", "tests");
	HL3

	return 0;
}
