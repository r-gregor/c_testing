/*
 * ubuild.h / v1
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 *       at 01:01:35 / 04:01:25
 * ---
 * 20231113_01 (en)
 * 20231113_02 (d)
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

#define PATH_SEP "/"
#define PATH_SEP_LEN (sizeof(PATH_SEP) -1)

/* Instead of int count -> int ignore: dummy first argument.
 * But if first arg is not count, we don't know how many args are there, so we
 * must supply NULL as terminating argument. Since it is 'A PAIN' to always start varargs
 * with dummy and ending them with NULL, we create implementation function, and then wrap
 * the function inside simpler macro!
 * Take a look at how VARIADIC MACROS must be constructed:
 *     https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
 *     https://en.cppreference.com/w/c/language/variadic
 * Even though 'ignore' holds dummy value it still indicates the arg after which the variadic
 * arguments start (in va_start function)
 */
const char *path_impl(int ignore, ...) {

	/* determine the lenghth of arguments */
	size_t length = 0;    /* length of arguments */
	ssize_t seps = -1;    /* number of separators - starts with -1 since there is one less seps than args */
	va_list args;

	/* start of 1-st loop over arguments to get lengths */
	va_start(args, ignore);
#if 0
	/* with while loop */
	const char *arg = va_arg(args, const char *);
	while(arg != NULL) {
		length += strlen(arg);
		seps   += 1;
		arg = va_arg(args, const char *);
	}
#else
	/* with for loop */
	/* for (for const char *arg = va_arg(args, const char *); arg != NULL; arg = va_arg(args, const char *)) {} */
	for (const char *arg = va_arg(args, const char *);
		             arg != NULL;
		             arg = va_arg(args, const char *))
	{
		length += strlen(arg);
		seps   += 1;
	}
#endif
	va_end(args); /* end of 1st loop */

	assert(length > 0);

	/* allocate memory for path: args + seps */
	size_t result_cap = length + seps * PATH_SEP_LEN + 1;
	char *result = malloc(result_cap);
	memset(result, 0, result_cap);

	/* start od 2-nd loop to fill in args and seps */
	length = 0;
	va_start(args, ignore);
	for (const char *arg = va_arg(args, const char *);
		             arg != NULL;
		             arg = va_arg(args, const char *))
	{
		size_t n = strlen(arg);
		memcpy(result + length, arg, n);
		length += n;

		/* for all args but last one -> seps only between args */
		if (seps > 0) {
			memcpy(result + length, PATH_SEP, PATH_SEP_LEN);
			length += PATH_SEP_LEN;
			seps -= 1;
		}
		/* result[length] = '\0'; NOT needed any more, because of memset() */
	}
	va_end(args);

	return result;
}

#define PATH(...) path_impl(69, __VA_ARGS__, NULL)

