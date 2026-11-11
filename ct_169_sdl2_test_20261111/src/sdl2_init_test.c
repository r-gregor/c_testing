#include <stdio.h>
#include <string.h>
#include <SDL.h>


int main(int argc, char **argv) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        /* printf("Unable to initialize SDL: '%s'\n" SDL_GetError()); */
        printf("[e] Unable to initialize SDL!\n\n");
        return 1;
    }
    printf("[+] SDL2 initialized successfully!\n\n");
    SDL_Quit();

	return 0;
}
