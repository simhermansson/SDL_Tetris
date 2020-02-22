#include "Tetromino.h"

Tetromino::Tetromino(vector<vector<SquareType>> shape) {
	this->shape = shape;
}

Tetromino::~Tetromino() {

}

bool Tetromino::collision() {
	return false;
}
