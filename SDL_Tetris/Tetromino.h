#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Tetromino {

public:
	Tetromino() = default;
	Tetromino(int x, int y, int tetrominoSize, vector<vector<SquareType>> shape);
	~Tetromino();

	// General methods.
	bool fall();
	void moveLeft();
	void moveRight();
	bool collision();

	// Getters.
	SquareType getSquare(int x, int y);

	int x;
	int y;

private:
	int tetrominoSize;
	vector<vector<SquareType>> shape;

	// Private methods.
	bool isWithin(int x, int y);
};

