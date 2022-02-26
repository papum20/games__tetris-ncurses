#include <ncurses/curses.h>
#include "piece.h"

#define MAX_ARRAY 200


class Game {
	protected:
		// LEVEL
		int width, height;
		WINDOW *gameWin;
		bool full_squares[MAX_ARRAY][MAX_ARRAY];
		int bg_color;	//background_color
		
		void createWindow();
	public:
		Game(int w, int h, int bgc);
		WINDOW* getWindow();
		char checkCollision(Piece piece, int x_input, int y_input);
		//return: x=x_collision, y=y_collision, b=both, n=no collision
		void drawPiece(Piece piece, bool drawing);
		//if(drawing) draws piece, else erases it
};