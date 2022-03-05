#include "piece.h"


Piece::Piece(int x, int y) {
	this->x = x;
	this->y = y;
	n_squares = 0;
	color = 0;
}
Piece::Piece() {
	x = 0;
	y = 0;
	n_squares = 0;
	color = 0;
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

chtype Piece::getColor() {
	return COLOR_PAIR(color);
}

piecePos Piece::getSquares(int xOffset, int yOffset) {
	piecePos tmp;
	tmp.n_squares = n_squares;
	for(int i = 0; i < n_squares; i++) {
		tmp.xPiece[i] = squares[i].getX() + x + xOffset;
		tmp.yPiece[i] = squares[i].getY() + y + yOffset;
	}
	return tmp;
}
piecePos Piece::getNormalSquares(int xOffset, int yOffset) {
	piecePos tmp = getSquares(xOffset, yOffset);
	//get min x,y to use as translation vector so it's drawn in top-left corner
	int xT = tmp.xPiece[0], yT = tmp.yPiece[0];
	for(int i = 1; i < MAX_SQUARES; i++) {
		if(tmp.xPiece[i] < xT) xT = tmp.xPiece[i];
		if(tmp.yPiece[i] < yT) yT = tmp.yPiece[i];
	}
	//translate
	for(int i = 0; i < tmp.n_squares; i++) {
		tmp.yPiece[i] -= yT;
		tmp.xPiece[i] -= xT;
	}

	return tmp;
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
	color = new_piece + 1;
	x = GAME_WIDTH / 2;
	y = -2;		//-MAX_SQUARES + 1;
}


void Piece::rotate(Game grid) {
	for(int i = 0; i < n_squares; i++) squares[i].rotateAroundOrigin();
	if(grid.checkCollision(getSquares()) ) {
		if(!grid.checkCollision(getSquares(1, 0)) )			 move(1, 0);
		else if(!grid.checkCollision(getSquares(-1, 0)) )	move(-1, 0);
		else if(!grid.checkCollision(getSquares(0, -1)) )	move(0, -1);
		else
			for(int i = 0; i < n_squares; i++) squares[i].unRotateAroundOrigin();
	}
}