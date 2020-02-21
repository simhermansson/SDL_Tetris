#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) {
	// Set basic size and position variables.
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	// Set drawing rectangle variables.
	this->squareType = EMPTY;
	if (!loadSurface()) {
		printf("Failed to load rectangle surface! SDL_Error: %s\n", SDL_GetError());
	}
	this->rectangle.x = x;
	this->rectangle.y = y;
	this->rectangle.w = width;
	this->rectangle.h = height;
}

Rectangle::~Rectangle() {

}

bool Rectangle::loadSurface() {
	bool success = true;
	this->surface = SDL_LoadBMP("rectangle.bmp");
	if (surface == NULL) success = false;
	return success;
}

void Rectangle::draw(SDL_Surface* windowSurface) {
	SDL_BlitScaled(surface, NULL, windowSurface, &rectangle);
}

int Rectangle::posX() { return x; }

int Rectangle::posY() { return y; }

void Rectangle::setSquareType(SquareType squareType) {
	this->squareType = squareType;
}

int Rectangle::getWidth() { return width; }

int Rectangle::getHeight() { return height; }
