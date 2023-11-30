#define NOBUILD_IMPLEMENTATION
#include <stdio.h>
#include <string.h>
#include "nobuild.h"

#define CFLAGS "-Wall", "-Wextra", "-Wswitch-enum", "-std=c11", "-pedantic", "-ggdb"
#define LIBS "-lm"
#define CC "gcc"

char const *cc(void) {
	const char *result = getenv(CC);
	return result ? result : "gcc";
}


int main(int argc, char **argv) {

	GO_REBUILD_URSELF(argc, argv);
	CMD(cc(),CFLAGS, "-o", "./bin/wang", "main.c", LIBS);

	if (argc > 1) {
		if (strcmp(argv[1], "run") == 0) {
			CMD("./bin/wang");
		} else {
			PANIC("Uknkown subcommand %s", argv[1]);
		}
	}

	return 0;
}

