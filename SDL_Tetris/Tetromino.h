#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Tetromino {

public:
	Tetromino() = default;
	Tetromino(vector<vector<SquareType>> shape);
	~Tetromino();

	// Methods.
	bool collision();

private:
	vector<vector<SquareType>> shape;
};

