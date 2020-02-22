#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Board {

public:
	Board(int width, int height, int rectWidth, int rectHeight);
	~Board();

	// General methods.
	void initBoard();

	// Getters.
	Rectangle* getRectangleAt(int x, int y);

private:
	int width;
	int height;
	int rectWidth;
	int rectHeight;

	vector<vector<Rectangle>> board;
};

