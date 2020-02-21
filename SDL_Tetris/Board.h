#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Board {

public:
	Board(int width, int height, int rectWidth, int rectHeight);
	~Board();

	// General methods.
	void draw(SDL_Surface *surface);
	void initBoard();

private:
	int width;
	int height;
	int rectWidth;
	int rectHeight;

	vector<vector<Rectangle>> board;
};

