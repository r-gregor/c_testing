#include <curses.h>
#include <string.h> /* for strlen */
#include <sys/random.h> /* for getrandom */

int random0_7() {
	int num;
	getrandom(&num, sizeof(int), GRND_NONBLOCK);
	return (num & 7); /* from 0000 to 0111 */
}


int main(void) {

	int result = random0_7();
	printf("Random num (0-7): %d\n", result);
	



	return 0;
}
