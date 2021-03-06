#pragma once

#include <stdlib.h>
#include <time.h>
#include <unordered_map>

#include "Tetromino.h"

using namespace std;

class TetrominoMaker {

public:
	TetrominoMaker();

	// Getters.
	Tetromino getRandomTetromino(int x, int y);

private:
	// Constants.
	const int NUM_OF_TETROMINOES = 7;

	// Private variables.
	unordered_map<SquareType, vector<vector<SquareType>>> shapes;

	// Private methods.
	void initShapes();
	vector<vector<SquareType>> getTetrominoI();
	vector<vector<SquareType>> getTetrominoJ();
	vector<vector<SquareType>> getTetrominoL();
	vector<vector<SquareType>> getTetrominoO();
	vector<vector<SquareType>> getTetrominoS();
	vector<vector<SquareType>> getTetrominoT();
	vector<vector<SquareType>> getTetrominoZ();
};

