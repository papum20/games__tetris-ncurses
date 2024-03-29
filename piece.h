#ifndef PIECE_H
#define PIECE_H



#include <curses.h>
#include "square.h"
#include "game.h"



#define DFLT_PIECES_N 7
//dflt_pieces pieces, made each of max_squares squares, made of x,y
const float dflt_pieces[DFLT_PIECES_N][MAX_SQUARES][2] = {
	{{.5,-.5}, {.5,.5}, {-.5,.5}, {-.5,-.5}},		//square
	{{1,-1}, {-1,0}, {0,0}, {1,0}},					//left L
	{{-1,-1}, {-1,0}, {0,0}, {1,0}},				//right L
	{{0,-1}, {-1,0}, {0,0}, {1,0}},					//T
	{{-1.5,-.5}, {-.5,-.5}, {.5,-.5}, {1.5,-.5}},	//I
	{{.5,-.5}, {1.5,-.5}, {-.5,.5}, {.5,.5}},		//left S
	{{-1.5,-.5}, {-.5,-.5}, {-.5,.5}, {.5,.5}}		//right S
};



//x AND y OF SQUARES START FROM UP-LEFT = 0,0

class Piece {
	protected:
		float x, y;
		int n_squares;
		Square squares[MAX_SQUARES];
		int color;
		
	public:
		Piece(int x, int y);
		Piece();
		static void defineColors();
		//initializes colors for pieces
		piecePos getSquares(int xOffset = 0, int yOFfset = 0);
		//modifies ret_x and ret_y with squares's x and y, returns n_sqares
		piecePos getNormalSquares(int xOffset = 0, int yOffset = 0);
		//getSquares but coordinates are minimum and positive
		chtype getColor();
		//returns color as attribute
		short getColorPair();
		//returns color pair id
		void move(int x_move, int y_move);
		//changes x and y according to input
		void newPiece();
		//piece becomes a random piece
		void rotate(Game grid);
		//rotates by 90 degrees clockwise
};



#endif