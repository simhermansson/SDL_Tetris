#pragma once

#include <SDL.h>
#include <stdio.h>

class Rectangle {

public:
	Rectangle(int x, int y, int width, int height);
	~Rectangle();

	// Methods.
	bool loadSurface();
	void draw(SDL_Surface* windowSurface);
	int posX();
	int posY();
	int getWidth();
	int getHeight();

private:
	// Positioning variables.
	int x;
	int y;
	int width;
	int height;

	// Drawing variables.
	SDL_Rect rectangle;
	SDL_Surface* surface;
};
