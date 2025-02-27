/*
 * from: Coding in C as My Mouse Dies ...
 *        https://www.youtube.com/watch?v=UhJC0wsxc_I&t=4s
 *        at: 01:52:22/02:59:22
 */
#include <stdio.h>

void *my_memcpy(void *dest, void *src, size_t n);

void *my_memcpy(void *dest, void *src, size_t n) {
	char *d = dest;
	const char *s = src;

	/*
	 * for (size_t i = 0; i < n; ++i) {
	 * 	d[i] = s[i];
	 * }
	*/

	/* same ... */
	for (; n; n--) *d++ = *s++;

	return dest;
}

