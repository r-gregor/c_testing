/*
 * ubuild.h / v2
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 *       v1 at 01:01:35 / 04:01:25
 *       v2 at 01:18:49 / 04:01:25
 * ---
 * 20231113_01 (en)
 * 20231113_02 (d)
 * 20231114_03 (en) v2
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PATH_SEP "/"
#define PATH_SEP_LEN (sizeof(PATH_SEP) -1)

/* v2 */
#define FOR_EACH_VARGS(arg, args, body)                                \
	do {                                                               \
		va_start(args, ignore);                                        \
		for (const char *arg = va_arg(args, const char *);             \
						 arg != NULL;                                  \
						 arg = va_arg(args, const char *))             \
		{                                                              \
			body;                                                      \
		}                                                              \
		va_end(args);                                                  \
	} while(0)

/* Instead of int count -> int ignore: dummy first argument.
 * But if first arg is not count, we don't know how many args are there, so we
 * must supply NULL as terminating argument. Since it is 'A PAIN' to always start varargs
 * with dummy arg and ending them with NULL, the implementation function is created, and
 * then wraped inside simpler macro!
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

	/* v2 */
	FOR_EACH_VARGS(arg, args, {
		length += strlen(arg);
		seps   += 1;
	});

	assert(length > 0);

	/* allocate memory for path: args + seps */
	size_t result_cap = length + seps * PATH_SEP_LEN + 1;
	char *result = malloc(result_cap);
	memset(result, 0, result_cap);

	/* start od 2-nd loop to fill in args and seps */
	length = 0;
	FOR_EACH_VARGS(arg, args, {
		size_t n = strlen(arg);
		memcpy(result + length, arg, n);
		length += n;

		/* for all args but last one -> seps only between args */
		if (seps > 0) {
			memcpy(result + length, PATH_SEP, PATH_SEP_LEN);
			length += PATH_SEP_LEN;
			seps -= 1;
		}
	});

	return result;
}

#define PATH(...) path_impl(69, __VA_ARGS__, NULL)

/* v2 mkdir */
void mkdirs_impl(int ignore, ...) {
	size_t length = 0;
	ssize_t seps = -1;
	va_list args;

	FOR_EACH_VARGS(arg, args, {
		length += strlen(arg);
		seps   += 1;
	});

	assert(length > 0);

	size_t result_cap = length + seps * PATH_SEP_LEN + 1;
	char *result = malloc(result_cap);
	memset(result, 0, result_cap);

	length = 0;
	FOR_EACH_VARGS(arg, args, {
		size_t n = strlen(arg);
		memcpy(result + length, arg, n);
		length += n;

		if (seps > 0) {
			memcpy(result + length, PATH_SEP, PATH_SEP_LEN);
			length += PATH_SEP_LEN;
			seps -= 1;
		}

		/* result[length] = '\0';
		 * NOT needed any more because of memset! (look up)
		 */

		/* man 2 mkdir */
		printf("[INFO] mkdir %s\n", result);
		if (mkdir(result, 0755) < 0) {
			if (errno == EEXIST) {
				fprintf(stderr, "[WARN] directory %s already exists\n", result);
			} else {
				fprintf(stderr, "[ERROR] could not create directory %s: %s\n",
						result,
						strerror(errno));
				exit(1);
			}
		}
	});
}

#define MKDIRS(...) mkdirs_impl(69, __VA_ARGS__, NULL)

