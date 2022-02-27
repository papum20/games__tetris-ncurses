#include <ncurses/curses.h>
#include "piece.h"

#define MAX_ARRAY 200


class Game {
	protected:
		// LEVEL
		int width, height;
		WINDOW *gameWin;
		bool full_squares[MAX_ARRAY][MAX_ARRAY];	//y, x
		int bg_color;	//background_color
		
		void createWindow();
	public:
		Game(int w, int h, int bgc);
		WINDOW* getWindow();
		void checkCollision(Piece piece, int out[], int x_input, int y_input);
		//modifies out with x,y so it doesn't collide
		void drawPiece(Piece piece, bool drawing);
		//if(drawing) draws piece, else erases it
		void addToGrid(Piece piece);
		//adds piece to full_squares
};