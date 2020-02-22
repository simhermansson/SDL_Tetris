#include "TetrominoMaker.h"

TetrominoMaker::TetrominoMaker() {
	initShapes();
}

TetrominoMaker::~TetrominoMaker() {

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

Tetromino TetrominoMaker::getRandomTetromino() {
	Tetromino tetromino;
	switch (rand() % NUM_OF_TETROMINOES) {
	case 0:
		tetromino = Tetromino(getTetrominoI());
		break;
	case 1:
		tetromino = Tetromino(getTetrominoJ());
		break;
	case 2:
		tetromino = Tetromino(getTetrominoL());
		break;
	case 3:
		tetromino = Tetromino(getTetrominoO());
		break;
	case 4:
		tetromino = Tetromino(getTetrominoS());
		break;
	case 5:
		tetromino = Tetromino(getTetrominoT());
		break;
	case 6:
		tetromino = Tetromino(getTetrominoZ());
		break;
	}
	return tetromino;
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoI() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoJ() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoL() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoO() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoS() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoT() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}

vector<vector<SquareType>> TetrominoMaker::getTetrominoZ() {
	return vector<vector<SquareType>> {
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY}
	};
}
