#include <stdio.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>

// If you want to know more about what some function or type does or how to use it, just search it on a search
// engine. For example "SDL_CreateWindow" will lead you to a page explaining that function:
// https://wiki.libsdl.org/SDL2/SDL_CreateWindow

int main (int argc, char **argv) {
	// Initialize SDL.
	SDL_Init(0);
	
	// Create window. SDL_WINDOWPOS_UNDEFINED will let your operating system decide what position to put the window on.
	// SDL_Window* window = SDL_CreateWindow("Test window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 300, SDL_WINDOW_SHOWN);
	SDL_Window* window = SDL_CreateWindow("Test window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	
	// Create window surface, you can think of SDL_Surface as a canvas or an image where you can draw pixels.
	SDL_Surface* windowsurface = SDL_GetWindowSurface(window);
	
	// Store some colors into variables to make them easier to use.
	Uint32 white = SDL_MapRGB(windowsurface->format, 255, 255, 255);
	// Uint32 black = SDL_MapRGB(windowsurface->format, 0, 0, 0);
	Uint32 gray = SDL_MapRGB(windowsurface->format, 125, 125, 125);
	
	// Rectangle position.
	int x = 0;
	int y = 0;
	
	

	// Main loop. This is where most of the action happens.
	while (1) {
		// Handle input and other events, see the following links for more event types and other information about SDL_Event.
		// https://wiki.libsdl.org/SDL2/SDL_Event
		// https://wiki.libsdl.org/SDL2/SDL_EventType
		SDL_Event event = {0};
		while (SDL_PollEvent(&event)) {
			// There can be all kinds of events, like the window resizing.
			switch (event.type) {
				// When mouse is clicked, set rectangle x/y to that position.
				case SDL_MOUSEBUTTONDOWN:
					x = event.button.x;
					y = event.button.y;
					break;
				// When arrow keys or WASD are pressed, move the rectangle.
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_UP:
						case SDLK_w:
							y -= 10;
							break;
						case SDLK_DOWN:
						case SDLK_s:
							y += 10;
							break;
						case SDLK_LEFT:
						case SDLK_a:
							x -= 10;
							break;
						case SDLK_RIGHT:
						case SDLK_d:
							x += 10;
							break;
					}
					break;
				// Program is being closed, so just return out from the main function.
				case SDL_QUIT:
					return 0;
			}
		}
		
		// Fill the screen with gray (NULL results in a rectangle that fills the entire screen).
		SDL_FillRect(windowsurface, NULL, gray);
		
		// Draw rectangle, use the x and y variables as the position.
		SDL_Rect rect = { .x=x, .y=y, .w=100, .h=100 };
		SDL_FillRect(windowsurface, &rect, white);
		
		// Draw the window's surface onto the window.
		SDL_UpdateWindowSurface(window);
		
		// Make the program wait 16 milliseconds before continuing to the next loop iteration (this causes the loop to run at roughly 60 FPS).
		SDL_Delay(16);
	}

	printf("\n");

	return 0;
}

