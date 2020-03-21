#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Board {

public:
	Board(int width, int height, int rectWidth, int rectHeight, SDL_Surface *screen);

	// General methods.
	void initBoard();
	void findCompleteRows();

	// Getters.
	Rectangle* getRectangleAt(int x, int y);

private:
	int width;
	int height;
	int rectWidth;
	int rectHeight;
	SDL_Surface *screen;

	// Private methods.
	void removeRow(int row);

	vector<vector<Rectangle>> board;
};

