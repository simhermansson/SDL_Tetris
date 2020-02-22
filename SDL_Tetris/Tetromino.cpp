#include "Tetromino.h"

Tetromino::Tetromino(int x, int y, int tetrominoSize, vector<vector<SquareType>> shape) {
	this->x = x;
	this->y = y;
	this->tetrominoSize = tetrominoSize;
	this->shape = shape;
}

Tetromino::~Tetromino() {
}

bool Tetromino::fall(Board& board) {
	y++;
	if (collision(board)) {
		y--;
		becomeBoard(board);
		return false;
	}
	return true;
}

void Tetromino::moveLeft(Board& board) {
	x--;
	if (collision(board)) {
		x++;
	}
}

void Tetromino::moveRight(Board& board) {
	x++;
	if (collision(board)) {
		x--;
	}
}

void Tetromino::rotateLeft(Board& board) {
	vector<vector<SquareType>> newShape = {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
	vector<vector<SquareType>> oldShape = shape;

	for (int i = 0; i < tetrominoSize; i++) {
		for (int j = 0; j < tetrominoSize; j++) {
			newShape[j][tetrominoSize-1-i] = shape[i][j];
		}
	}

	shape = newShape;
	if (collision(board)) shape = oldShape;
}

void Tetromino::rotateRight(Board& board) {
	vector<vector<SquareType>> newShape = {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
	vector<vector<SquareType>> oldShape = shape;

	for (int i = 0; i < tetrominoSize; i++) {
		for (int j = 0; j < tetrominoSize; j++) {
			newShape[j][i] = shape[i][tetrominoSize - 1 - j];
		}
	}

	shape = newShape;
	if (collision(board)) shape = oldShape;
}

void Tetromino::drop(Board& board) {

}

void Tetromino::becomeBoard(Board& board) {
	for (int i = 0; i < tetrominoSize; i++) {
		for (int j = 0; j < tetrominoSize; j++) {
			if (shape[i][j] != EMPTY) {
				board.getRectangleAt(x + j, y + i)->setSquareType(shape[i][j]);
			}
		}
	}
}

bool Tetromino::collision(Board& board) {
	for (int i = 0; i < tetrominoSize; i++) {
		for (int j = 0; j < tetrominoSize; j++) {
			if (shape[i][j] != EMPTY && board.getRectangleAt(x + j, y + i)->getSquareType() != EMPTY) {
				return true;
			}
		}
	}
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
