#ifndef _UBUILD_H
#define _UBUILD_H
/*
 * ubuild.h / v6
 * from: New Build System in C — Part 1
 *       https://www.youtube.com/watch?v=n47AFxc1ksE
 * ---
 * 20231113_01 (en)
 * 20231113_02 (d)
 * 20231114_03 (en) v2: mkdir, new macros
 * 20231115_04 (en) v3: replace malloc with arena
 * ---
 * 20240523_05 (en) v4: PATH() --> CONCAT_SEP(), at 01:41:57 / 04:01:25
 *                      added param to FOREEACH_VARGS macro -> mkdirs first parameter 'ignore', or 'sep'
 * 20240524_06 (en) v5: join all interfaces from both header files into ubuild.h
 *                      and update driver *.c files and Makefile acordingly
 * 20240524_07 (en) v6: FOREACH_FILE_IN_DIR macro
 *                      source: https://stackoverflow.com/questions/25070751/navigating-through-files-using-dirent-h
 *
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define PATH_SEP "/"

/* v3 */
#define ARENA_CAP 1024
char buffer[ARENA_CAP];

/* v2 */
#define FOREACH_VARGS(param, arg, args, body)                          \
	do {                                                               \
		va_start(args, param);                                         \
		for (const char *arg = va_arg(args, const char *);             \
			             arg != NULL;                                  \
			             arg = va_arg(args, const char *))             \
		{                                                              \
			body;                                                      \
		}                                                              \
		va_end(args);                                                  \
	} while(0)

/*
 * v5: from uconcat.h
 */
const char *concat_impl(int ignore, ...) {
	size_t length = 0;
	va_list args;
	FOREACH_VARGS(ignore, arg, args, {
		length += strlen(arg);
	});

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
 * ---
 * 20240522: PATH() REPLACED BY CONCAT_SEP() !!
 * ---
 */


/*
 * v4: 20240522
 * INSTEAD OF PATH() !!
 */
const char *concat_sep_impl(const char *sep, ...) {

	/* determine the lenghth of arguments */
	size_t sep_len = strlen(sep);
	size_t length = 0;            /* length of arguments */
	ssize_t seps_count = -1;      /* number of separators - starts with -1 since there is one less seps_count than args */
	va_list args;

	/* v2 */
	FOREACH_VARGS(sep, arg, args, {
		length += strlen(arg);
		seps_count   += 1;
	});

	assert(length > 0);

	/* allocate memory for path: args + seps_count */
	// size_t result_cap = length + seps_count * sep_len + 1;
	char *result = buffer;
	memset(result, 0, ARENA_CAP);

	/* start on 2-nd loop to fill in args and seps_count */
	length = 0;
	FOREACH_VARGS(sep, arg, args, {
		size_t n = strlen(arg);
		memcpy(result + length, arg, n);
		length += n;

		/* for all args but last one -> seps_count only between args */
		if (seps_count > 0) {
			memcpy(result + length, sep, sep_len);
			length += sep_len;
			seps_count -= 1;
		}
	});

	return result;
}

#define CONCAT_SEP(sep, ...) concat_sep_impl(sep, __VA_ARGS__, NULL)
#define PATH(...) CONCAT_SEP(PATH_SEP, __VA_ARGS__)


/*
 * v4
 */
void mkdirs_sep_impl(const char *sep, ...) {
	size_t sep_len = strlen(sep);
	size_t length = 0;
	ssize_t seps_count = -1;
	va_list args;

	FOREACH_VARGS(sep, arg, args, {
		length += strlen(arg);
		seps_count   += 1;
	});

	assert(length > 0);

	/* v3 */
	char *result = buffer;
	memset(result, 0, ARENA_CAP);

	length = 0;
	FOREACH_VARGS(sep, arg, args, {
		size_t n = strlen(arg);
		memcpy(result + length, arg, n);
		length += n;

		if (seps_count > 0) {
			memcpy(result + length, sep, sep_len);
			length += sep_len;
			seps_count -= 1;
		}

		printf("[INFO] mkdir %s\n", result);

		/* man 2 mkdir */
		/* for WIN it only takes one argument -- NO mode */
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
#define MKDIRS_SEP(sep, ...) mkdirs_sep_impl(sep, __VA_ARGS__, NULL)
#define MKDIRS(...) MKDIRS_SEP(PATH_SEP, __VA_ARGS__)

/*
 * v6
 */

#define FOREACH_FILE_IN_DIR(file, dirpath, body) {  \
	do {                                            \
		struct dirent *dp = NULL;                   \
		DIR *dir = opendir(dirpath);                \
			while ( (dp=readdir(dir)) ) {           \
				const char *file = dp->d_name;      \
				body;                               \
			}                                       \
			closedir(dir);                          \
	} while(0);                                     \
}                                                   \

#endif
