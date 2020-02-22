#include "Board.h"

Board::Board(int width, int height, int rectWidth, int rectHeight) {
	this->width = width;
	this->height = height;
	this->rectWidth = rectWidth;
	this->rectHeight = rectHeight;

	initBoard();
}

Board::~Board() {

}

void Board::initBoard() {
	// Init rectangles.
	for (int i = 0; i < height; i++) {
		vector<Rectangle> row;
		for (int j = 0; j < width; j++) {
			Rectangle rectangle(j * rectWidth, i * rectHeight, rectWidth, rectHeight);
			row.push_back(rectangle);
		}
		board.push_back(row);
	}
}

Rectangle* Board::getRectangleAt(int x, int y) {
	return &board[y][x];
}
