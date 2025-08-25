/*******************************************************************************
* Program: Horse Race
* Description: A horse race 'game' for the terminal in C.
* YouTube Lesson: https://www.youtube.com/watch?v=I8mZ5m-6TF0
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include the library with the sleep function for the current platform 
//
// If on a Windows system we can count on _WIN32 defined, otherwise we assume
// we are on a POSIX system (Unix-like systems like MacOS, Linux)
//
#ifdef _WIN32 
	#include <windows.h>
#else
	#include <unistd.h>
#endif
  
// Defines the number of horses and length of the track
#define NUM_HORSES 8
#define TRACK_LENGTH 40

// Custom sleeop function which calls the right sleep function for the platform
void sleep_ms(int milliseconds)
{
#ifdef _WIN32
	Sleep(milliseconds);
#else
	usleep(milliseconds * 1000); 
#endif
}

// Prints the state of the race to the terminal given the horse positions
void print_race(int positions[])
{
	// For each horse we print a track
	for (int i = 0; i < NUM_HORSES; i++)
	{
		// Print the track for this horse, outputting the horse where they are
		// currently positioned on the track
		printf("|");
		for (int j = 0; j < TRACK_LENGTH; j++)
		{
			if (j == positions[i]) printf("🐎");
			else printf("-");
		}
		printf("| (Horse %d)\n", i + 1);
	}

	// Ensures that all the text above is output to the terminal and not 
	// buffered in stdout
	fflush(stdout); 
}

int main(void)
{
	// Keeps track of the position of the horses
	int positions[NUM_HORSES];

	// Keeps track of the ultimate winner horse
	int winner;

	// Keeps track of the horses (and number of horses) that cross the finish 
	// line during the last 'frame of animation'
	int winners[NUM_HORSES];
	int total_winners = 0;

	// Seed the random number generator
	srand( (unsigned int) time(NULL) );

	// Initially all horses begin on the far right of the track
	for (int i = 0; i < NUM_HORSES; i++)
	{
		positions[i] = TRACK_LENGTH - 1;
	}

	// Output the initial state of the game to the terminal
	print_race(positions);
	
	// A crude 'game loop' that updates the game state and then outputs the next
	// 'frame of animation', the loop continues so long as no horse has won
	while (total_winners == 0)
	{
		// Update each horses position
		for (int i = 0; i < NUM_HORSES; i++)
		{
			// Move each horse towards the finish between 0-2 positions with
			// each frame of animation, determined randomly
			positions[i] -= rand() % 3; 

			// If a horse 'crosses the finish line' then add them to the 
			// winners array
			if (positions[i] <= 0)
			{
				// Set the horse's position to 0 so they are drawn at the end
				// of the track
				positions[i] = 0;

				// Add the horse to the winners array and increment the count
				// of the total number of winners so that the next winning 
				// horse is stored into the winners array.	It's possible 
				// multiple horses will finish in this same frame of animation,
				// in which case we'll chose the ultimate win from this array.
				winners[total_winners] = i;
				total_winners++;
			}
		}

		// Sleep so that the animation does not happen so quickly it is not 
		// visible
		sleep_ms(200);
		
		// In order to animate on the terminal we need to draw over the 
		// existing output of the game, to do so we move the cursor back
		// to where it was before previously drawing the state of the game.
		//
		// An ANSI escape sequence... \033 is the escape character that tells 
		// the terminal to expect an instruction, [ is the control sequence 
		// introducer and then #A will move the cursor up # amount of lines. 
		printf("\033[%dA", NUM_HORSES);

		// Output the state of the game to the terminal and overwrite the 
		// existing output in the process
		print_race(positions);	  
	}

	// Randomly select the ultimate winner horse from any horse that crossed 
	// the finish line during the last frame of animation
	winner = winners[ rand() % total_winners ];
	
	// Output the winning horse number
	printf("\n🏆 Horse %d wins the race!\n", winner + 1);

	return 0;
}
