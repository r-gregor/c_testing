/*
 * fname: main.c
 * 20260901 v1:
 * 20260901 v2:
 * last 20260901
 */
#include <stdio.h>
#include <string.h>
#include <mylibrary.h>

void SV_info(char *);

int main(int argc, char **argv) {

	// String_View line = SV_init("Hy, my name is Gregor Redelonghi");
	// SV_print(&line);

	SV_info("Hy, my name is Gregor Redelonghi");
	SV_info("My WIFE's name is Tadeja Mali Redelonghi");

	return 0;
}



void SV_info(char *line) {
	String_View sv = SV_init(line);
	SV_print(&sv);
}

