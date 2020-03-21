#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Board {

public:
	Board(int width, int height, int rectWidth, int rectHeight);

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

	// Private methods.
	void removeRow(int row);

	vector<vector<Rectangle>> board;
};

