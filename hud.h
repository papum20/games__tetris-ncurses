#ifndef HUD_H
#define HUD_H

#include <curses.h>
#include "common.h"



class Hud {
	protected:
		WINDOW *nextPieceWin;
		WINDOW *scoreWin;
	public:
		Hud(int xNextP, int yNextP, int xScore, int yScore);
		Hud(int xNextP, int yNextP) : Hud(xNextP, yNextP, xNextP, yNextP + NEXT_WIN_HEIGHT) {};
		void drawPiece(piecePos piece, chtype color, bool drawing);
		//if(drawing) draws piece, else erases it
};


#endif