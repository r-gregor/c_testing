/*
 * from: Coding in C as My Mouse Dies ...
 *        https://www.youtube.com/watch?v=UhJC0wsxc_I&t=4s
 *        at: 01:50:57/02:59:22
 */
#include <stdio.h>
size_t my_strlen(const char *s);

size_t my_strlen(const char *s) {
	size_t n = 0;
	while(*s++) n++;
	return n;
}

