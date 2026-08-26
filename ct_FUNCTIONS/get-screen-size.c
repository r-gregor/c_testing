/* get-screen-size */
#include <sys/ioctl.h>
#include <unistd.h>

void get_screen_size();

void get_screen_size() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf ("lines %d\n", w.ws_row);
	printf ("columns %d\n", w.ws_col);
}

