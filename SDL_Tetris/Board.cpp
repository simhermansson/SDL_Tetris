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

void Board::draw(SDL_Surface *surface) {
	// Call draw on background rectangles.
	for (auto &row : board) {
		for (auto &rect : row) {
			rect.draw(surface);
		}
	}
}

void Board::initBoard() {
	// Init rectangles.
	for (int i = 0; i < height; i++) {
		vector<Rectangle> row(width);
		for (int j = 0; j < width; j++) {
			Rectangle rectangle(j * rectWidth, i * rectHeight, rectWidth, rectHeight);
			row.push_back(rectangle);
		}
		board.push_back(row);
	}
}
