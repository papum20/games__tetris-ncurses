#include <curses.h>
#include "piece.h"

#define MAX_ARRAY 200


class Game {
	protected:
		// LEVEL
		int width, height;
		WINDOW *gameWin;
		bool full_squares[MAX_ARRAY][MAX_ARRAY];	//y, x
		int bg_color;	//background_color
		
		void createWindow(int start_x, int start_y);
	public:
		Game(int start_x, int start_y, int w, int h, int bgc);
		WINDOW* getWindow();
		void checkCollision(Piece piece, int move[], int x_input, int y_input);
		//modifies move with x,y so it doesn't collide (only one between x,y has value != 0)
		void drawPiece(Piece piece, bool drawing);
		//if(drawing) draws piece, else erases it
		//bool pieceToEnd(Piece piece);
		////if piece at last line
		void addToGrid(Piece piece);
		//adds piece to full_squares
};