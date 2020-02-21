#include "Tetromino.h"

Tetromino::Tetromino(vector<vector<Rectangle>> *shape) {
	this->shape = shape;
}

Tetromino::~Tetromino() {
	free(shape);
}

bool Tetromino::collision() {
	return false;
}
