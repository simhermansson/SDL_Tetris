#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) {
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
	if (!loadSurface()) {
		printf("Failed to load rectangle surface! SDL_Error: %s\n", SDL_GetError());
	}
}

Rectangle::~Rectangle() {

}

void Rectangle::initSurfaceMap() {
	surfaceMap = {
		{EMPTY, 0x000000},
		{I, 0xFF0000},
		{J, 0x0FF000},
		{L, 0x00FF00},
		{O, 0x000FF0},
		{S, 0x0000FF},
		{T, 0x0F000F},
		{Z, 0xF0F00F}
	};
}

bool Rectangle::loadSurface() {
	bool success = true;
	this->surface = SDL_LoadBMP("rectangle.bmp");
	if (surface == NULL) success = false;
	return success;
}

void Rectangle::draw(SDL_Surface *windowSurface) {
	SDL_FillRect(surface, NULL, surfaceMap[squareType]);
	SDL_BlitScaled(surface, NULL, windowSurface, &rectangle);
}

void Rectangle::drawSquareAt(int x, int y, SquareType squareType, SDL_Surface *windowSurface) {
	int oldX = rectangle.x;
	int oldY = rectangle.y;
	rectangle.x = x * width;
	rectangle.y = y * height;
	SDL_FillRect(surface, NULL, surfaceMap[squareType]);
	SDL_BlitScaled(surface, NULL, windowSurface, &rectangle);
	rectangle.x = oldX;
	rectangle.y = oldY;
}

int Rectangle::posX() { return x; }

int Rectangle::posY() { return y; }

void Rectangle::setSquareType(SquareType squareType) {
	this->squareType = squareType;
}

int Rectangle::getWidth() { return width; }

int Rectangle::getHeight() { return height; }
