#ifndef GAME_H
#define GAME_H


#include <curses.h>
#include "common.h"
#include "inputManager.h"
#include "hud.h"

#define MAX_ARRAY 200
#define EMPTY_SQUARE 0


class Game {
	protected:
		// LEVEL
		int width, height;
		WINDOW *gameWin;
		WINDOW *debugWin;
		short full_squares[MAX_ARRAY][MAX_ARRAY];	//y, x
		int bg_color;	//background_color
		
		void createWindow(int start_x, int start_y);
		int checkLine(int line);
		//returns -1 if empty line, 1 if full line, else 0
	public:
		Game(int start_x, int start_y, int w, int h, int bgc);
		void clearWindow();
		//clears game window
		bool checkCollision(piecePos piece);
		//
		bool checkGameOver(piecePos piece);
		//check game over
		void drawPiece(piecePos piece, bool drawing);
		//if(drawing) draws piece, else erases it
		void addToGrid(piecePos piece);
		//adds piece to full_squares
		int moveLine();
		//checks completed lines and moves down; returs number of completed lines
		
		void debug();
};


#endif