#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

void draw_line_across_screen();

int main (int argc, char **argv) {
	draw_line_across_screen();

	return 0;  // make sure your main returns int
}

void draw_line_across_screen() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	// printf ("lines %d\n", w.ws_row);
	// printf ("columns %d\n", w.ws_col);
	for (int i = 0; i < w.ws_col; i++) {
		putchar('-');
	}
	putchar('\n');
}
