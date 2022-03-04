#include <curses.h>
#include "common.h"


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