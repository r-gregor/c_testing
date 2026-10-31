# fname: README.txt
# 20260828
# ---

This project is also conditional compilation example:

[c source code file]
#include <stdio.h>
#include <string.h>

#define NL printf("\n");
#define clr() printf("\033[H\033[J")

/* conditional copilation */
#if defined(PRINTOUT)
	#define GO_ON {} /* does NOTHING! */
#else
	#define GO_ON {              \
		NL                       \
		printf("[next ->]");     \
		getchar();               \
		clr();                   \
	}
#endif

/* === function and structs initializations === */
/* ... */

/* === main === */
int main(int argc, char **argv) {
	clr();

#if defined(PRINTOUT)
	printf("!!THIS IS A PRINTOUT!!\n\n");
#endif

	sep(); // ---
	/* ... */
	GO_ON // this runs differently acording to conditional compilation */

	sep(); // ---
	/* ... */
	NL
	/* ... */
	GO_ON // this runs differently acording to conditional compilation */

	NL
	end();
	return 0;

} /* end main */


/* === functions declarations === */
/* ... */


[ HOW TO USE ]
// build and run
// APP="${1}"
APP="c-source-code-file.c" // 'c-source-code-file.c'
APPNAME="${APP%.*}"        // 'c-source-code-file'

if [ ! -f "${APP}" ]; then
	printf "[ERROR] no such file: %s\n" "${APP}"
	exit
fi

/* build and run with PRINTOUT set */
gcc -DPRINTOUT -o ./build/${APPNAME}-printout ${APP} && ./build/${APPNAME}-printout /* build AND run, or */
gcc -DPRINTOUT -o ./build/${APPNAME}-printout ${APP}                              /* just build        */

/* build and run without PRINTOUT set */
gcc -o ./build/${APPNAME} ${APP} && ./build/${APPNAME} /* build AND run, or */
gcc -o ./build/${APPNAME} ${APP}                     /* just build        */

