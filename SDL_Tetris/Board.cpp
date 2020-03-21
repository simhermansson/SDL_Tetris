#include "Board.h"

Board::Board(int width, int height, int rectWidth, int rectHeight, SDL_Surface *screen) {
	this->width = width;
	this->height = height;
	this->rectWidth = rectWidth;
	this->rectHeight = rectHeight;
	this->screen = screen;

	initBoard();
}

void Board::initBoard() {
	// Init upper out of bounds.
	for (int i = 2; i > 0; i--) {
		vector<Rectangle> upperBounds;
		for (int j = -1; j <= width; j++) {
			Rectangle rectangle(j * rectWidth, i * -rectHeight, rectWidth, rectHeight, screen);
			rectangle.setSquareType(OUTSIDE);
			upperBounds.push_back(rectangle);
		}
		board.push_back(upperBounds);
	}

	// Init game area.
	for (int i = 0; i < height; i++) {
		vector<Rectangle> row;
		for (int j = -1; j <= width; j++) {
			Rectangle rectangle(j * rectWidth, i * rectHeight, rectWidth, rectHeight, screen);
			if (j == -1 || j == width) rectangle.setSquareType(OUTSIDE);
			row.push_back(rectangle);
		}
		board.push_back(row);
	}

	// Init lower out of bounds.
	for (int i = 0; i < 2; i++) {
		vector<Rectangle> lowerBounds;
		for (int j = -1; j <= width; j++) {
			Rectangle rectangle(j * rectWidth, (height + i) * rectHeight, rectWidth, rectHeight, screen);
			rectangle.setSquareType(OUTSIDE);
			lowerBounds.push_back(rectangle);
		}
		board.push_back(lowerBounds);
	}
}

void Board::findCompleteRows() {
	for (int row = 0; row < height; row++) {
		int filledBlocks = 0;
		for (int column = 0; column < width; column++) {
			if (getRectangleAt(column, row)->getSquareType() != EMPTY) {
				filledBlocks++;
			} else break;
		}
		if (filledBlocks == width) {
			removeRow(row);
		}
	}
}

void Board::removeRow(int row) {
	for (; row > 0; row--) {
		for (int column = 0; column < width; column++) {
			getRectangleAt(column, row)->setSquareType(getRectangleAt(column, row - 1)->getSquareType());
		}
	}
}

Rectangle* Board::getRectangleAt(int x, int y) {
	return &board[y+2][x+1];
}
