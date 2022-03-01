#include <curses.h>
#include <stdlib.h>
#include "square.h"


#define GAME_WIDTH 20

#define MAX_SQUARES 4
#define DFLT_PIECES_N 7
//dflt_pieces pieces, made each of max_squares squares, made of x,y
const int dflt_pieces[DFLT_PIECES_N][MAX_SQUARES][2] = {
	{{0,0}, {0,1}, {1,0}, {1,1}},	//square
	{{1,0}, {1,1}, {0,2}, {1,2}},	//left L
	{{0,0}, {0,1}, {0,2}, {1,2}},	//right L
	{{0,0}, {1,0}, {2,0}, {1,1}},	//T
	{{0,0}, {0,1}, {0,2}, {0,3}},	//I
	{{1,0}, {0,1}, {1,1}, {0,2}},	//left S
	{{0,0}, {0,1}, {1,1}, {1,2}},	//right S
};


//x AND y OF SQUARES START FROM UP-LEFT = 0,0

class Piece {
	protected:
		int x, y;
		int n_squares;
		Square squares[MAX_SQUARES];
		int color;
		
		void defineColors();
		//initializes colors for pieces
	public:
		Piece(int x, int y);
		Piece();
		int getSquares(int ret_x[], int ret_y[]);
		//modifies ret_x and ret_y with squares's x and y, returns n_sqares
		chtype getColor();
		//returns color as attribute
		void move(int x_move, int y_move);
		//changes x and y according to input
		void newPiece();
		//piece becomes a random piece
		void rotate();
		//rotates by 90 degrees clockwise
};