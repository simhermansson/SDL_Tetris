#pragma once

#include <vector>

#include "Rectangle.h"

using namespace std;

class Tetromino {

public:
	Tetromino(vector<vector<Rectangle>> *shape);
	~Tetromino();

	// Methods.
	bool collision();

private:
	vector<vector<Rectangle>> *shape;
};

