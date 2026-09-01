#ifndef STRING_VIEW_H_
#define STRING_VIEW_H_

/*
 * from:  C Strings are Terrible! (Tsoding)
 *        https://www.youtube.com/watch?v=y8PLpDgZc0E
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for free() */
#include <ctype.h> /* for isspace */

#define SV_fmt "%.*s"
#define SV_args(sv) (sv)->count, (sv)->data
#define NL printf("\n");
#define clr() printf("\033[H\033[J")

#if defined(PRINTOUT)
	#define GO_ON {}
#else
	#define GO_ON {              \
		NL                       \
		printf("[next ->]");     \
		getchar();               \
		clr();                   \
	}
#endif

/* === FUNCTION AND STRUCTS INITIALIZATIONS === */
void end();
void sep();
void sep_long();

typedef struct {
	const char *data;
	unsigned int count;
} String_View;

String_View sv(const char *cstr);
void sv_print_simple(String_View *sv);
void sv_print(String_View *sv, char *prefix, char border);
void sv_chop_right(String_View *sv);
void sv_chop_left(String_View *sv);
void sv_chop_n_right(String_View *sv, unsigned int n);
void sv_chop_n_left(String_View *sv, unsigned int n);
void sv_trim_left(String_View *sv);
void sv_trim_right(String_View *sv);
void sv_trim(String_View *sv);
String_View sv_chop_by_delim(String_View *sv, char delim);


/* === FUNCTIONS DECLARATIONS === */
void sep() {
	printf("---\n");
}

void sep_long() {
	for (int i=0; i<80; ++i) {
		putchar('-');
	}
	NL
}

/* for E2 */
/* convert c-string to String_View sv */
String_View sv(const char *cstr) {
	return (String_View) {
		.data = cstr,
		.count = strlen(cstr),
	};
}

/* simple printf of sv  */
void sv_print_simple(String_View *sv) {
	printf(SV_fmt, SV_args(sv));
}

/* printf of sv with 'prefix' and 'border' */
void sv_print(String_View *sv, char *prefix, char border) {
	if (border == 0) {
		printf("%s" SV_fmt "\n", prefix, SV_args(sv));
	} else {
		printf("%s%c" SV_fmt "%c\n", prefix, border, SV_args(sv), border);
	}
}

/* chop off single char from left */
void sv_chop_left(String_View *sv) {
	if (sv->count == 0) return;
	sv->count -= 1;
	sv->data += 1;
}

/* chop off single char from right */
void sv_chop_right(String_View *sv) {
	if (sv->count == 0) return;
	sv->count -= 1;
}

/* chop off n chars from left */
void sv_chop_n_left(String_View *sv, unsigned int n) {
	if (n > sv->count) n =sv->count;
	sv->count -= n;
	sv->data += n;
}

/* chop off n chars from right */
void sv_chop_n_right(String_View *sv, unsigned int n) {
	if (n > sv->count) n =sv->count;
	sv->count -= n;
}

/* trim off all leading spaces of a string */
void sv_trim_left(String_View *sv) {
	while (sv->count > 0 && isspace(sv->data[0])) {
		sv_chop_n_left(sv, 1);
	}
}

/* trim off all trailing spaces of a string */
void sv_trim_right(String_View *sv) {
	while (sv->count > 0 && isspace(sv->data[sv->count-1])) {
		sv_chop_n_right(sv, 1);
	}
}

/* trim off both leading and trailing spaces - both sv_trim_(left/right) functions combined */
void sv_trim(String_View *sv) {
	sv_trim_left(sv);
	sv_trim_right(sv);
}

/*
 * split string into 2 strings by 'delim', or
 * chop off and return entire string if felimiter NOT found
 */
String_View sv_chop_by_delim(String_View *sv, char delim) {
	size_t del_pos = 0;
	while (del_pos < sv->count && sv->data[del_pos] != delim) {
		del_pos += 1;
	}

	/* if delim found */
	if(del_pos < sv->count) {
		/* construct first part of the string up to but exclusive delim */
		String_View result = {
			.data = sv->data,
			.count = del_pos,
		};

		/* return rest of the string (after delim, and without delim) */
		sv_chop_n_left(sv, del_pos + 1);

		/* return first part of the string up to but exclusive delim */
		return result;
	}

	/* if delim NOT found: return the entire string, but also chop off entire string */
	String_View result = *sv;
	sv_chop_n_left(sv, sv->count);
	return result;
}

#endif

