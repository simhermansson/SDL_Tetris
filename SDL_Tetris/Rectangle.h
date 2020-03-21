#pragma once

#include <SDL.h>
#include <stdio.h>
#include <unordered_map>

#include "SquareType.h"

using namespace std;

class Rectangle {

public:
	Rectangle() = default;
	Rectangle(int x, int y, int width, int height, SDL_Surface *screen);

	// General methods.
	bool loadSurface(SDL_Surface *screen);
	void initSurfaceMap();
	void draw(SDL_Surface *windowSurface);
	void drawSquare(SquareType squareType, SDL_Surface *windowSurface);

	// Setters.
	void setSquareType(SquareType squareType);

	// Getters.
	int posX();
	int posY();
	int getWidth();
	int getHeight();
	SquareType getSquareType();

private:
	// Positioning variables.
	int x;
	int y;
	int width;
	int height;

	// Drawing variables.
	unordered_map<SquareType, int> surfaceMap;
	SquareType squareType;
	SDL_Rect rectangle;
	SDL_Surface *surface;
};

