#ifndef GAME_H
#define GAME_H


#include <curses.h>
#include "common.h"

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
		bool checkCollision(piecePos piece);
		//
		void drawPiece(piecePos piece, chtype color, bool drawing);
		//if(drawing) draws piece, else erases it
		void addToGrid(piecePos piece);
		//adds piece to full_squares
};


#endif