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
	// Init upper out of bounds.
	vector<Rectangle> upperBounds;
	for (int i = 0; i < width; i++) {
		Rectangle rectangle(i * rectWidth, -rectHeight, rectWidth, rectHeight);
		rectangle.setSquareType(OUTSIDE);
		upperBounds.push_back(rectangle);
	}
	board.push_back(upperBounds);

	// Init game area.
	for (int i = 0; i < height; i++) {
		vector<Rectangle> row;
		for (int j = -1; j <= width; j++) {
			Rectangle rectangle(j * rectWidth, i * rectHeight, rectWidth, rectHeight);
			if (j == -1 || j == width) rectangle.setSquareType(OUTSIDE);
			row.push_back(rectangle);
		}
		board.push_back(row);
	}

	// Init lower out of bounds.
	vector<Rectangle> lowerBounds;
	for (int i = 0; i < width; i++) {
		Rectangle rectangle(i * rectWidth, height * rectHeight, rectWidth, rectHeight);
		rectangle.setSquareType(OUTSIDE);
		lowerBounds.push_back(rectangle);
	}
	board.push_back(lowerBounds);
}

Rectangle* Board::getRectangleAt(int x, int y) {
	return &board[y+1][x+1];
}
