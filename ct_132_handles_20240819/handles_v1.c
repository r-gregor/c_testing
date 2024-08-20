/*
 * handles_v1.c
 * 2024089_01_en: v1
 *
 */

#include <stdio.h>
#include <string.h>


int main(void) {

	{	/* local scope */
		int Timers[10];
		Timers[0] = 60;
		Timers[1] = 160;

		/* Handle as int array index */
		const int Handle = 0;
		const int TimeRemaining = Timers[Handle];

		printf("Time remaining: %3d s\n", TimeRemaining);
	}

	{	/* local scope */
		int Timers[10];
		Timers[0] = 70;
		Timers[1] = 170;

		/* Handle as pointer to an array index */
		const int Index = 0;
		const int *Handle = &Timers[Index];
		const int TimeRemaining = *Handle;

		printf("Time remaining: %3d s\n", TimeRemaining);
	}

	{	/* local scope */
		int Timers[10];
		Timers[0] = 80;
		Timers[1] = 180;

		/* Handle as pointer to an array index */
		/* Handle selected with pointer arithmetics */
		const int Index = 1;
		const int *Handle = Timers + Index;
		const int TimeRemaining = *Handle;

		printf("Time remaining: %3d s\n", TimeRemaining);
	}

	return 0;
}

