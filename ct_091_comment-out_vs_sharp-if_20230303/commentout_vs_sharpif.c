#include <stdio.h>
#include <string.h>

/*
 * TWO ways to NOT run part of program:
 * 1 - commentig that part out, or
 * 2 - puting that part inside #if -- #endif block:
 *		#if 0 -- #endif ... NOT run
 *		#if 1 -- #endif ... RUN
 */

int main(int argc, char **argv) {

	// DISPLAY ALL:
	printf("DISPLAYING ALL ...\n");
	printf("1-st line is displayed always.\n"); // always shows 
	printf("2-nd line is commented out!\n"); // removed by commenting out
	printf("3-rd line is removed from execution by #if 0 -- #endif blocki\n"); // removed by #if -- #endif block

	printf("---\n");

	printf("HIDING 2nd LINE (commenting it out)...\n");
	printf("1-st line is displayed allways.\n"); // always shows 
	/*
	printf("2-nd line is commented out!\n"); // removed by commenting out
	*/

	#if 1
	printf("3-rd line is removed from execution by #if 0 -- #endif blocki\n"); // removed by #if -- #endif block
	#endif

	printf("---\n");

	printf("HIDING 3nd LINE (#if -- #endif block)...\n");
	printf("1-st line is displayed allways.\n"); // always shows 
	/*
	printf("2-md line is commented out!\n"); // removed by commenting out
	*/

	#if 0
	printf("3-rd line is removed from execution by #if 0 -- #endif block"); // removed by #if -- #endif block
	#endif

	return 0;
}

