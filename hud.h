#ifndef HUD_H
#define HUD_H

#include <curses.h>
#include "common.h"

#define NEXT_WIN_WIDTH 6
#define NEXT_WIN_HEIGHT 4
#define SCORE_WIN_WIDTH 6
#define SCORE_WIN_HEIGHT 4


class Hud {
	private:
		WINDOW *nextPieceWin;
		WINDOW *scoreWin;
	public:
		Hud(int xNextP, int yNextP, int xScore, int yScore);
		Hud(int xNextP, int yNextP);
		void drawPiece(piecePos piece, chtype color, bool drawing);
		//if(drawing) draws piece, else erases it
};


#endif