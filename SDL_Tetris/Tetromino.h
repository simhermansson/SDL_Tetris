#pragma once

#include <vector>

#include "Board.h"
#include "Rectangle.h"

using namespace std;

class Tetromino {

public:
	Tetromino() = default;
	Tetromino(int x, int y, int tetrominoSize, vector<vector<SquareType>> shape);
	~Tetromino();

	// General methods.
	void fall(Board& board);
	void moveLeft(Board& board);
	void moveRight(Board& board);
	void rotateLeft(Board& board);
	void rotateRight(Board& board);
	void drop(Board& board);
	bool collision(Board& board);
	bool isPartOfBoard();

	// Getters.
	SquareType getSquare(int x, int y);

private:
	int x;
	int y;
	int tetrominoSize;
	bool partOfBoard;
	vector<vector<SquareType>> shape;

	// Private methods.
	bool isWithin(int x, int y);
	void becomeBoard(Board& board);
};

