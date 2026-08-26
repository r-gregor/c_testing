#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

void get_screen_size();

int main (int argc, char **argv) {
	get_screen_size();

	return 0;
}

void get_screen_size() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf ("lines %d\n", w.ws_row);
	printf ("columns %d\n", w.ws_col);
}

