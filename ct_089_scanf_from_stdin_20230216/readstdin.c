/*
 * v1
 * from:  "Scanf scansets, and reading a CSV file in C (fixed)"
 *        https://www.youtube.com/watch?v=k0BIzHDBkwE
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {

	char item[BUFSIZE];

	/* s1 */
	/*
	while (scanf("%s", item)!= EOF) {
		printf("item: %s\n", item);
	}
	*/

	/* s2 */
	/*
	while (scanf("%[a-zA_Z0-9]", item)!= EOF) {
		printf("item: %s\n", item);
	}
	*/

	/* s3-1 */
	// while (scanf("%[^,]", item)!= EOF) { // same as V2
	
	/* s3-2 */
	// while (scanf("%[^,]%*c", item)!= EOF) {
	
	/* s3-3 */
	while (scanf("%[^,\n]%*c", item)!= EOF) {
		printf("item: %s\n", item);
	}

	return 0;
}

