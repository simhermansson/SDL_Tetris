#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, SDL_Surface *screen) {
	// Set basic size and position variables.
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->rectangle.x = x;
	this->rectangle.y = y;
	this->rectangle.w = width;
	this->rectangle.h = height;

	// Set drawing rectangle variables.
	initSurfaceMap();
	this->squareType = EMPTY;
	if (!loadSurface(screen)) {
		printf("Failed to load rectangle surface! SDL_Error: %s\n", SDL_GetError());
	}
}

void Rectangle::initSurfaceMap() {
	surfaceMap = {
		{EMPTY, 0xC3C3C3},
		{I, 0x2DC7CC},
		{J, 0x0341AE},
		{L, 0xFF971C},
		{O, 0xFFD500},
		{S, 0x72CB3B},
		{T, 0xEF2098},
		{Z, 0xFF3213}
	};
}

bool Rectangle::loadSurface(SDL_Surface *screen) {
	bool success = true;
	this->surface = SDL_CreateRGBSurface(surfaceMap[squareType], width, height, screen->format->BitsPerPixel,
										 screen->format->Rmask, screen->format->Gmask,
										 screen->format->Bmask, screen->format->Amask);
	if (surface == NULL) success = false;
	return success;
}

void Rectangle::draw(SDL_Surface *windowSurface) {
	SDL_FillRect(surface, NULL, surfaceMap[squareType]);
	SDL_BlitScaled(surface, NULL, windowSurface, &rectangle);
}

void Rectangle::drawSquare(SquareType squareType, SDL_Surface *windowSurface) {
	SDL_FillRect(surface, NULL, surfaceMap[squareType]);
	SDL_BlitScaled(surface, NULL, windowSurface, &rectangle);
}

SquareType Rectangle::getSquareType() {
	return squareType;
}

int Rectangle::posX() { return x; }

int Rectangle::posY() { return y; }

void Rectangle::setSquareType(SquareType squareType) {
	this->squareType = squareType;
}

int Rectangle::getWidth() { return width; }

int Rectangle::getHeight() { return height; }
