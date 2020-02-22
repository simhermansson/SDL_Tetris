#include "Tetromino.h"

Tetromino::Tetromino(int x, int y, int tetrominoSize, vector<vector<SquareType>> shape) {
	this->x = x;
	this->y = y;
	this->tetrominoSize = tetrominoSize;
	this->shape = shape;
}

Tetromino::~Tetromino() {
}

bool Tetromino::fall() {
	y++;
	if (collision()) {
		y--;
		return false;
	}
	return true;
}

void Tetromino::moveLeft() {
	x--;
	if (collision()) {
		x++;
	}
}

void Tetromino::moveRight() {
	x++;
	if (collision()) {
		x--;
	}
}

bool Tetromino::collision() {
	return false;
}

bool Tetromino::isWithin(int x, int y) {
	return this->x <= x && x < this->x + tetrominoSize &&
		   this->y <= y && y < this->y + tetrominoSize;
}

SquareType Tetromino::getSquare(int x, int y) {
	if (!isWithin(x, y)) return EMPTY;
	else {
		return shape[y - this->y][x - this->x];
	}
}
