#include <curses.h>
#include "square.h"

#define MAX_SQUARES 4


//x AND y OF SQUARES START FROM UP-LEFT = 0,0

class Piece {
	protected:
		int x, y;
		int n_squares;
		Square squares[MAX_SQUARES];
		int color;
	public:
		Piece(int x, int y, int n, Square sq[], int c, int bgc);
		Piece();
		void move(int x_move, int y_move);
		//changes x and y according to input
		int getSquares(int ret_x[], int ret_y[]);
		//modifies ret_x and ret_y with squares's x and y, returns n_sqares
		int getColor();
		//returns color as attribute
};