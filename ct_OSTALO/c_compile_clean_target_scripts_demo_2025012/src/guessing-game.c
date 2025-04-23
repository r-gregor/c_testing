#include <curses.h>
#include <string.h> /* for strlen */
#include <sys/random.h> /* for getrandom */

int random0_7() {
	int num;
	getrandom(&num, sizeof(int), GRND_NONBLOCK);
	return (num & 7); /* from 0000 to 0111 */
}

int read_guess() {
	int ch;
	do {
		ch = getch();
	} while ((ch < '0') || (ch > '7'));
	return (ch - '0'); /* turn into a number */
}

void print_header(const char *text) {
	move(0, 0);
	clrtoeol();
	attron(A_BOLD);
	mvaddstr(0, (COLS / 2) - (strlen(text) / 2), text);
	attroff(A_BOLD);
	refresh();
}

void print_status(const char *text) {
	move(LINES - 1, 0);
	clrtoeol();
	attron(A_REVERSE);
	mvaddstr(LINES - 1, 0, text);
	attroff(A_REVERSE);
	refresh();
}

int main() {
	int number, guess;
	initscr();
	cbreak();
	noecho();
	number = random0_7();
	mvprintw(1, COLS - 1, "%d", number); /* debugging */
	print_header("Guess the number 0-7");
	mvaddstr(9, (COLS / 2) - 7, "0 1 2 3 4 5 6 7");
	print_status("Make a guess...");
	do {
		guess = read_guess();
		move(10, (COLS / 2) - 7 + (guess * 2));
		if (guess < number) {
			addch('[');
			print_status("Too low");
		}
		else if (guess > number) {
			addch(']');
			print_status("Too high");
		}
		else {
			addch('^');
		}
	} while (guess != number);
	print_header("That's right!");
	print_status("Press any key to quit");
	getch();
	endwin();
	return 0;
}

