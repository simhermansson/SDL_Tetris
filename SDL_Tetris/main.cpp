#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Rectangle.h"

// Constants.
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 800;
const int GAME_WIDTH = 10;
const int GAME_HEIGHT = 20;
const int RECTANGLE_WIDTH = SCREEN_WIDTH / GAME_WIDTH;
const int RECTANGLE_HEIGHT = SCREEN_HEIGHT / GAME_HEIGHT;

// Rendering window.
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gSplashScreen = NULL;

// Game variables.
std::vector<Rectangle> gRectangles;

// Function headers.
void splashScreen();
void gameLoop();
void draw();
bool handleInput();
bool init();
bool loadMedia();
SDL_Surface* loadSurface(const std::string& path);
void close();

int main(int argc, char* args[]) {
	if (init() && !loadMedia()) {
		printf("Failed to load media!\n");
	}
	// Start game loop;
	splashScreen();
	gameLoop();

	// Free resources and close application.
	close();
	return 0;
}

void splashScreen() {
	// Blit splash screen and show for 3 seconds.
	SDL_BlitSurface(gSplashScreen, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindow);
	SDL_Delay(3000);
}

void gameLoop() {
	// Init game objects;
	for (int i = 0; i < GAME_HEIGHT; i++) {
		for (int j = 0; j < GAME_WIDTH; j++) {
			Rectangle rectangle(j * RECTANGLE_WIDTH, i * RECTANGLE_HEIGHT, RECTANGLE_WIDTH, RECTANGLE_HEIGHT);
			gRectangles.push_back(rectangle);
		}
	}

	// Main game loop.
	while (!handleInput()) {
		draw();
	}
}

void draw() {
	// Clear screen.
	SDL_FillRect(gSplashScreen, NULL, 0x000000);

	// Call draw on background rectangles.
	for (Rectangle r : gRectangles) {
		r.draw(gScreenSurface);
	}

	// Call draw on tetrominoes.
	/*
	for (Tetronimo t : gTetronimos) {
		t.draw(gScreenSurface);
	}
	*/

	// Update window.
	SDL_UpdateWindowSurface(gWindow);
}

bool handleInput() {
	bool quit = false;

	// Event handler.
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			quit = true;
		}
		else if (e.type = SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
				break;
			default:
				break;
			}
		}
	}

	return quit;
}

bool init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to init SDL! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		// Create window.
		gWindow = SDL_CreateWindow("SDL_Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Failed to create window! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			// Get main window surface.
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia() {
	bool success = true;

	// Load splash screen.
	gSplashScreen = loadSurface("splash_screen.bmp");
	if (gSplashScreen == NULL) {
		printf("Unable to load splash screen! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}

SDL_Surface* loadSurface(const std::string& path) {
	// Load BMP image at path, returns NULL if not found.
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	if (surface == NULL) {
		printf("Failed to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
	}

	return surface;
}

void close() {
	// Deallocate surface.
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	// Destroy window.
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}