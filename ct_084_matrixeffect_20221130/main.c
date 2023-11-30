/*
 * FROM:
 * How to Program Matrix Style Dripping Text (terminal, C, curses example)
 * Jacob Sorber
 * https://www.youtube.com/watch?v=K8dCh3ZMLN8
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "ui.h"
#include "matrix.h"

#define ITERATIONS 300
#define REFRESH_DELAY 50000

int main(int argc, char **argv) {

	if (!init_ui()) {
		return EXIT_FAILURE;
	}

	matrix_init();

	for (int i=0; ITERATIONS; i++) {
		matrix_update();
		show_matrix();
		usleep(REFRESH_DELAY);
	}

	cleanup_ui();
	return EXIT_SUCCESS;
}

