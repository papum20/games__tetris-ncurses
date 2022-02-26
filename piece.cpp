#include "piece.h"


Piece::Piece(int x, int y, int n, Square sq[], int c) {
	this->x = x;
	this->y = y;
	n_squares = n;
	for(int i = 0; i < n; i++) squares[i] = sq[i];
	color = c;
}

Piece::Piece() {
	x = 0;
	y = 0;
	n_squares = 0;
	color = 0;
}


void Piece::move(int x_move, int y_move) {
	x += x_move;
	y += y_move;
}



int Piece::getSquares(int ret_x[], int ret_y[]) {
	for(int i = 0; i < n_squares; i++) {
		ret_x[i] = squares[i].getX() + x;
		ret_y[i] = squares[i].getY() + y;
	}
	return n_squares;
}



int Piece::getColor() {
	return COLOR_PAIR(color);
}