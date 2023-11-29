#include <stdio.h>
#include <time.h>

void twirlybar(void) {
	static clock_t last = 0;
	static const char *dir = "|/-\\";
	static size_t angle = 0;
	clock_t now;
	
	now = clock();
	if((now - last) / (CLOCKS_PER_SEC / 10.0) >= 0.5) {
		// if(++angle == sizeof(dir)/sizeof(*dir)) angle = 0;
		if(++angle == sizeof(dir)/sizeof(char)) angle = 0;
	last = now;
	}

	putchar('\b');
	putchar(dir[angle]);
	fflush(stdout);
}


/** main */
int main(void) {
	for(;;) twirlybar();

	return 0;
}

