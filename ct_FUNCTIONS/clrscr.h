// workaround tested on Windows(cmd.exe), Linux(Bash and zsh) and OS X(zsh):
#ifndef _CLRSCR_H
#define _CLRSCR_H
#include <stdlib.h>

void clrscr();

void clrscr() {
    system("@cls||clear");
}

#endif

