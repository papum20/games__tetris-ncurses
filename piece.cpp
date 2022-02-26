#include "piece.h"


Piece::Piece(int x, int y) {
	this->x = x;
	this->y = y;
	n_squares = 0;
	color = 0;
	defineColors();
}
Piece::Piece() {
	x = 0;
	y = 0;
	n_squares = 0;
	color = 0;
	defineColors();
}


Piece::defineColors() {
	init_pair(0, COLOR_WHITE, COLOR_BLACK);	//square
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);	//left L
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);	//right L
	init_pair(3, COLOR_CYAN, COLOR_BLACK);	//T
	init_pair(4, COLOR_BLUE, COLOR_BLACK);	//I
	init_pair(5, COLOR_GREEN, COLOR_BLACK);	//left S
	init_pair(6, COLOR_RED, COLOR_BLACK);	//right S
}


//// GET

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


//// GAME

void Piece::move(int x_move, int y_move) {
	x += x_move;
	y += y_move;
}


void Piece::newPiece() {
	int new_piece = rand()%DFLT_PIECES_N;
	int n_squares = MAX_SQUARES;
	for(int i = 0; i < n_squares; i++) {
		tmp_piece = dflt_pieces[new_piece][i];
		squares[i] = Square(tmp_piece[0], tmp_piece[1]);
	}
	color = new_piece;
}
