/*
 * fname: c-string-to-string-view-testing.c
 * from:  C Strings are Terrible! (Tsoding)
 *        https://www.youtube.com/watch?v=y8PLpDgZc0E
 * 20260828 v5
 * last: 20260828
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for free()

/* for isspace */
#include <ctype.h>

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

/* === function and structs initializations === */
void end();
void sep();
void sep_long();

/* for E2 */
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

/* === main === */
int main(int argc, char **argv) {

#if 1
	clr();
#if defined(PRINTOUT)
	printf("!!THIS IS A PRINTOUT!!\n\n");
#endif
	/* E1 */
	/* classic c-string */
	printf("#########################\n");
	printf("# [E1] classic c-string #\n");
	printf("#########################\n");
	char *s = "Hello, World!";
	printf("printing 's' as string '%%s':\n");
	printf("s = '%s'\n", s);

	sep(); // ---
	printf("'s' is a pointer '%%p':\n");
	printf(" s = '%p'\n", s);
	printf("sizeof(s) = %zu\n", sizeof(s));

	sep(); // ---
	printf("dereferenced '*s' as '%%ld': '%ld'\n", *s);
	printf("dereferenced '*s' as '%%c':  '%c'\n", *s);
	printf("('%c' is '%d' in ASCII table)\n", *s, *s);
	printf("sizeof(*s) = %zu (dereferenced 'char *' is just a pointer to the first char)\n", sizeof(*s));
	GO_ON

	sep(); // ---
	printf("'s' represents just a view of bytes stored somewhere in memory\n");
	printf("    and we can change that view:\n");
	printf("Let's print 's + 1':\n");
	printf("s = '%s'\n", s + 1);
	printf("... which is ideal for chopping off chars from left\n");
	printf("but chopping off from right is not possible with string literals\n");
	printf("as we need to 'change' last char of read-only string litteral to '\\0'\n");
	printf("if we try to set s[strlen(s) - 1] = '\\0', the program will segfault\n");
	printf("because we try to touch memory that we are not supposed to touch\n");
	printf("chopping off from right is possible if we duplicae the string, but \n");
	printf("that means allocating new memory that need to be freed after use\n");
	GO_ON

	sep(); // ---
	printf("duplicating string litteral with: char *sc = strdup(\"Hello, World\");\n");
	char *sc = strdup("Hello, World");
	int n = strlen(sc);
	printf("sc[n-1] = '\\0'\n");
	sc[n-1] = '\0';
	printf("sc = '%s'\n", sc);
	printf("sizeof(*sc) = %zu\n", sizeof(*sc));
	free(sc);
	sep_long(); // ------------------
	GO_ON
#endif

#if 1
	clr();
#ifdef PRINTOUT
	printf("!!THIS IS A PRINTOUT!!\n\n");
#endif
	/* E2 */
	/* string-view */
	printf("####################\n");
	printf("# [E2] string-view #\n");
	printf("####################\n");
	printf("c-string is a single pointer to memory address at the beginning of charcter array\n");
	printf("string-view has two integers: 'pointer' at the addres at the beginning of string and 'length'\n");
	printf("it is very easy to convert null-terminated string into string-view because we just ignore the\n");
	printf("'\\0' character without allocating any memory or destroying any data\n\n");
	
	String_View sv2 = sv("Hello, World");

	sv_print(&sv2, "sv2 = ", '\'');
	GO_ON

	sep(); // ---
	printf("if we want to chop off from right, we need to use special printf format string count:\n");
	printf("printf(\"%%.*s\"), sv2.count, sv2.data);\n");
	printf("expression because original printf does not respect our '.count'\n");
	printf("expression is included inside 'sv_print()' function, or\n");
	printf("we can factor out the printf format string count into macro definition, like:\n");
	printf("\t#define SV_fmt \"%%.*s\"\n");
	printf("\t#define SV_args(sv2) (sv2)->count, (sv2)->data\n");

	NL
	printf("so 'printf(\"|%%.*s|\", sv2.count, sv2.data);' becomes: 'printf(\"|\" SV_fmt \"|\", SV_args(sv2));'\n");
	printf("this works because you can combine several parts of string literal into single one:\n");
	printf("printf(\"'First \" \"part\" \" and \" \"second \" \"part'\") ==> ");
	printf("'First " "part" " and " "second " "part'\n");
	GO_ON

	sep(); // ---
	printf("new functions 'sv_chop_(left/right)' to chop off single char:\n");
	sv_print(&sv2, "sv2 = ", '\'');

	NL
	printf("after chopping off from right 2 times:\n");
	sv_chop_right(&sv2);
	sv_chop_right(&sv2);
	sv_print(&sv2, "sv2 = ", '\'');

	NL
	printf("and after chopping off from left 2 times:\n");
	sv_chop_left(&sv2);
	sv_chop_left(&sv2);
	sv_print(&sv2, "sv2 = ", '\'');
	GO_ON

	sep(); // ---
	printf("new functions 'sv_chop_n_(left/right)' to accept number of characters to chop off\n");
	String_View sv3 = sv("Hello, World");
	sv_print(&sv3, "sv3 = ", '\'');

	NL
	printf("and after chopping off from right 3 times and from left 2 times:\n");
	sv_chop_n_right(&sv3, 3);
	sv_chop_n_left(&sv3, 2);
	sv_print(&sv3, "sv3 = ", '\'');
	GO_ON

	sep(); // ---
	printf("new functions 'sv_trim_(left/right)' to trim off leading or trailing spaces from string-view:\n");
	String_View sv4 = sv("      Hello, World      ");
	sv_print(&sv4, "sv4 = ", '|');

	NL
	printf("after trimming from left:\n");
	sv_trim_left(&sv4);
	sv_print(&sv4, "sv4 = ", '|');

	NL
	printf("and after trimming from right:\n");
	sv_trim_right(&sv4);
	sv_print(&sv4, "sv4 = ", '|');
	GO_ON

	sep(); // ---
	printf("new function 'sv_trim()' to trim off leading AND trailing spaces from string-view:\n");
	String_View sv5 = sv("          Hello, World              ");
	sv_print(&sv5, "sv5 = ", '|');

	NL
	printf("after trimming:\n");
	sv_trim(&sv5);
	sv_print(&sv5, "sv5 = ", '|');
	GO_ON

	sep(); // ---
	printf("new function 'sv_chop_by_delim()' to split string-view into two parts by delim:\n");
	String_View sv6 = sv("Hello, World");
	sv_print(&sv6, "sv6 = ", '|');

	NL
	printf("after splitting:\n");
	String_View hello = sv_chop_by_delim(&sv6, ',');
	sv_print(&hello, "first part:  ", '|');
	sv_print(  &sv6, "second part: ", '|');

#endif

	NL
	end();
	return 0;

} /* end main */


/* === functions declarations === */
void begin() {
	printf("[INFO] result:\n\n");
}

void end() {
	printf("[INFO] end\n---\n");
}

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

/* v3 */
/* trim off both leading and trailing spaces - both sv_trim_(left/right) functions combined */
void sv_trim(String_View *sv) {
	sv_trim_left(sv);
	sv_trim_right(sv);
}

/* split string into 2 strings by 'delim', or
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

