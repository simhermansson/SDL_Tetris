#pragma once

#include <SDL.h>
#include <stdio.h>
#include <unordered_map>

#include "SquareType.h"

using namespace std;

class Rectangle {

public:
	Rectangle() = default;
	Rectangle(int x, int y, int width, int height);
	~Rectangle();

	// General methods.
	bool loadSurface();
	void initSurfaceMap();
	void draw(SDL_Surface *windowSurface);
	void drawSquareAt(int x, int y, SquareType squareType, SDL_Surface *windowSurface);
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
	unordered_map<SquareType, int> surfaceMap;
	SquareType squareType;
	SDL_Rect rectangle;
	SDL_Surface* surface;
};

