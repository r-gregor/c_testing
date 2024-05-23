/*
 * uconcat.h
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 *       at 01:25:35 / 04:01:25
 * ---
 * 20231115_01 (en)
 * ---
 * 20240523_02 (en) v2: added param to FOREACH_...() macro
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ARENA_CAP 1024
char buffer[ARENA_CAP];

#define FOREACH_VARGS(param, arg, args, body)                         \
	do {                                                               \
		va_start(args, param);                                        \
		for (const char *arg = va_arg(args, const char *);             \
						 arg != NULL;                                  \
						 arg = va_arg(args, const char *))             \
		{                                                              \
			body;                                                      \
		}                                                              \
		va_end(args);                                                  \
	} while(0)


const char *concat_impl(int ignore, ...) {
	size_t length = 0;
	va_list args;
	FOREACH_VARGS(ignore, arg, args, {
			length += strlen(arg);
	});

	// char *result = malloc(length + 1);
	char *result = buffer;
	memset(result, 0, ARENA_CAP);

	length = 0;
	FOREACH_VARGS(ignore, arg, args, {
			size_t n = strlen(arg);
			memcpy(result + length, arg, n);
			length += n;
	});

	return result;
}

#define CONCAT(...) concat_impl(69, __VA_ARGS__, NULL)

