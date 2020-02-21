#pragma once

#include <SDL.h>
#include <stdio.h>

#include "SquareType.h"

class Rectangle {

public:
	Rectangle() = default;
	Rectangle(int x, int y, int width, int height);
	~Rectangle();

	// General methods.
	bool loadSurface();
	void draw(SDL_Surface* windowSurface);
	int posX();
	int posY();

	// Setters.
	void setSquareType(SquareType squareType);

	// Getters.
	int getWidth();
	int getHeight();

private:
	// Positioning variables.
	int x;
	int y;
	int width;
	int height;

	// Drawing variables.
	SquareType squareType;
	SDL_Rect rectangle;
	SDL_Surface* surface;
};

