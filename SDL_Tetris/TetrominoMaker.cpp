#include "TetrominoMaker.h"

TetrominoMaker::TetrominoMaker() {
	srand(time(NULL));
	initShapes();
}

void TetrominoMaker::initShapes() {
	shapes = {
		{I, getTetrominoI()},
		{J, getTetrominoJ()},
		{L, getTetrominoL()},
		{O, getTetrominoO()},
		{S, getTetrominoS()},
		{T, getTetrominoT()},
		{Z, getTetrominoZ()}
	};
}

Tetromino TetrominoMaker::getRandomTetromino(int x, int y) {
	Tetromino tetromino;
	switch (rand() % NUM_OF_TETROMINOES) {
	case 0:
		tetromino = Tetromino(x, y, 4, getTetrominoI());
		break;
	case 1:
		tetromino = Tetromino(x, y, 3, getTetrominoJ());
		break;
	case 2:
		tetromino = Tetromino(x, y, 3, getTetrominoL());
		break;
	case 3:
		tetromino = Tetromino(x, y, 2, getTetrominoO());
		break;
	case 4:
		tetromino = Tetromino(x, y, 3, getTetrominoS());
		break;
	case 5:
		tetromino = Tetromino(x, y, 3, getTetrominoT());
		break;
	case 6:
		tetromino = Tetromino(x, y, 3, getTetrominoZ());
		break;
	}
	return tetromino;
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoI() {
	return vector<vector<SquareType>> {
		{I, I, I, I},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoJ() {
	return vector<vector<SquareType>> {
		{J, EMPTY, EMPTY},
		{J, J, J},
		{EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoL() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, L},
		{L, L, L},
		{EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoO() {
	return vector<vector<SquareType>> {
		{O, O},
		{O, O}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoS() {
	return vector<vector<SquareType>> {
		{EMPTY, S, S},
		{S, S, EMPTY},
		{EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoT() {
	return vector<vector<SquareType>> {
		{EMPTY, T, EMPTY},
		{T, T, T},
		{EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoZ() {
	return vector<vector<SquareType>> {
		{Z, Z, EMPTY},
		{EMPTY, Z, Z},
		{EMPTY, EMPTY, EMPTY}
	};
}
