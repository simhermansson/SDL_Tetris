#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "Rectangle.h"
#include "Board.h"
#include "Tetromino.h"
#include "TetrominoMaker.h"

// Constants.
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 800;
const int GAME_WIDTH = 10;
const int GAME_HEIGHT = 20;
const int RECTANGLE_WIDTH = SCREEN_WIDTH / GAME_WIDTH;
const int RECTANGLE_HEIGHT = SCREEN_HEIGHT / GAME_HEIGHT;
const int TETROMINO_START_X = 5;
const int TETROMINO_START_Y = 0;

// Rendering window.
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gSplashScreen = NULL;

// Game variables.
Board *board;

// Function headers.
void splashScreen();
void gameLoop();
void draw(Tetromino& currentTetromino);
void drawRect(int x, int y, Tetromino& currentTetromino);
bool handleInput(Tetromino& currentTetromino);
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
	// Blit splash screen and show for 2 seconds.
	SDL_BlitSurface(gSplashScreen, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindow);
	SDL_Delay(2000);
}

void gameLoop() {
	// Init board;
	board = new Board(GAME_WIDTH, GAME_HEIGHT, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, gScreenSurface);
	// Init the tetrominoMaker and the first tetromino.
	TetrominoMaker tetrominoMaker;
	Tetromino currentTetromino = tetrominoMaker.getRandomTetromino(TETROMINO_START_X, TETROMINO_START_Y);

	// Main game loop.
	unsigned int lastTime = 0, lastDrawTime = 0, currentTime;
	while (true) {
		// Check for player input and if player wants to exit.
		if (handleInput(currentTetromino)) {
			break;
		}

		currentTime = SDL_GetTicks();
		// Handle falling down.
		if (!currentTetromino.isPartOfBoard() && currentTime > lastTime + 500) {
			lastTime = currentTime;
			currentTetromino.fall(*board);
		}

		//Create new tetromino if collision detected and end game if new one collides as well.
		if (currentTetromino.isPartOfBoard()) {
			currentTetromino = tetrominoMaker.getRandomTetromino(TETROMINO_START_X, TETROMINO_START_Y);
			// Check if player has lost.
			if (currentTetromino.collision(*board)) {
				break;
			}
		}

		// Draw game.
		if (currentTime > lastDrawTime + 1000 / 60) {
			lastDrawTime = currentTime;
			draw(currentTetromino);
		}
	}
}

void draw(Tetromino& currentTetromino) {
	// Draw board and tetrominoes.
	for (int i = 0; i < GAME_HEIGHT; i++) {
		for (int j = 0; j < GAME_WIDTH; j++) {
			drawRect(j, i, currentTetromino);
		}
	}

	// Update window.
	SDL_UpdateWindowSurface(gWindow);
}

void drawRect(int x, int y, Tetromino& currentTetromino) {
	if (currentTetromino.getSquare(x, y) != EMPTY) {
		board->getRectangleAt(x, y)->drawSquare(currentTetromino.getSquare(x, y), gScreenSurface);
	}
	else {
		board->getRectangleAt(x, y)->draw(gScreenSurface);
	}
}

bool handleInput(Tetromino& currentTetromino) {
	bool quit = false;

	// Event handler.
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			quit = true;
		}
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				currentTetromino.rotateLeft(*board);
				break;
			case SDLK_DOWN:
				currentTetromino.rotateRight(*board);
				break;
			case SDLK_LEFT:
				currentTetromino.moveLeft(*board);
				break;
			case SDLK_RIGHT:
				currentTetromino.moveRight(*board);
				break;
			case SDLK_SPACE:
				currentTetromino.drop(*board);
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
	// Free board.
	delete board;

	// Deallocate surface.
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	// Destroy window.
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}