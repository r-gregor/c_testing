#include <stdio.h>
#include <string.h>
#include <SDL.h>


int main(int argc, char **argv) {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("[e] unable to initialize SDL: '%s'\n\n", SDL_GetError());
		return 1;
	}
	printf("[+] SDL2 initialized successfully!\n\n");
	SDL_Quit();

	return 0;
}

