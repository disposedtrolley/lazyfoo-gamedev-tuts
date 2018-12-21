#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;	// The window being rendered to.

	SDL_Surface* screenSurface = NULL;	// A 2D image being rendered.

	// Initialise SDL and check for any errors. We only care about SDL's video subsystem at this stage.
	// SDL_Init() returns -1 if any errors are thrown.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		// We don't care where the window is shown, so we use SDL_WINDOWPOS_UNDEFINED for the x and y coordinates.
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			// Get the surface of the window to draw on.
			screenSurface = SDL_GetWindowSurface(window);

			// Fill the surface with white, and call the update function to render the changes.
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);

			// FYI - SDL_Delay() inhibits user input.
			SDL_Delay(2000);

			SDL_DestroyWindow(window);
			SDL_Quit();

			return 0;
		}
	}
}