#include "piece.h"


Piece::Piece(int x, int y) {
	this->x = x;
	this->y = y;
	n_squares = 0;
	color = 0;
	defineColors();
}
Piece::Piece() {
	x = GAME_WIDTH / 2;
	y = -5;
}

void Piece::defineColors() {
	init_pair(1, COLOR_BLACK, COLOR_WHITE);		//square
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);	//left L
	init_pair(3, COLOR_BLACK, COLOR_MAGENTA);	//right L
	init_pair(4, COLOR_BLACK, COLOR_CYAN);		//T
	init_pair(5, COLOR_BLACK, COLOR_BLUE);		//I
	init_pair(6, COLOR_BLACK, COLOR_GREEN);		//left S
	init_pair(7, COLOR_BLACK, COLOR_RED);		//right S
}


//// GET

int Piece::getSquares(int ret_x[], int ret_y[]) {
	for(int i = 0; i < n_squares; i++) {
		ret_x[i] = squares[i].getX() + x;
		ret_y[i] = squares[i].getY() + y;
	}
	return n_squares;
}
chtype Piece::getColor() {
	return COLOR_PAIR(color);
}


//// GAME

void Piece::move(int x_move, int y_move) {
	x += x_move;
	y += y_move;
}


void Piece::newPiece() {
	int new_piece = rand()%DFLT_PIECES_N;
	n_squares = MAX_SQUARES;
	for(int i = 0; i < n_squares; i++)
		squares[i] = Square(dflt_pieces[new_piece][i][0], dflt_pieces[new_piece][i][1]);
	color = new_piece+1;
	x = GAME_WIDTH / 2;
	y = -MAX_SQUARES + 1;
}
