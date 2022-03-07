#ifndef HUD_H
#define HUD_H

#include <curses.h>
#include "common.h"

#define FAST_SCORE 1
#define LINE_SCORE 40


class Hud {
	protected:
		WINDOW *nextPieceWin;
		WINDOW *scoreWin;
		int score;
		int lines;
		//score:	+1 for each square at fast speed,
		//			+40 for each line
	public:
		Hud(int xNextP, int yNextP, int xScore, int yScore);
		Hud(int xNextP, int yNextP) : Hud(xNextP, yNextP, xNextP, yNextP + NEXT_WIN_HEIGHT) {};
		//SCORE
		void updateFastScore();
		void updateLineScore();
		void drawScore();
		//FUNCTIONS
		void drawPiece(piecePos piece, bool drawing);
		//if(drawing) draws piece, else erases it
};


#endif