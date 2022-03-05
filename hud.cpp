#include "hud.h"



Hud::Hud(int xNextP, int yNextP, int xScore, int yScore) {
	nextPieceWin = newwin(NEXT_WIN_HEIGHT, NEXT_WIN_WIDTH, yNextP, xNextP);
	scoreWin = newwin(SCORE_WIN_HEIGHT, SCORE_WIN_WIDTH, yScore, xScore);
	box(nextPieceWin, 0, 0);
	box(scoreWin, 0, 0);
	wrefresh(nextPieceWin);
	wrefresh(scoreWin);
}

Hud::Hud(int xNextP, int yNextP) {
	Hud(xNextP, yNextP, xNextP, yNextP + NEXT_WIN_HEIGHT);
}



void Hud::drawPiece(piecePos piece, chtype color, bool drawing) {
	if(drawing) wattron(nextPieceWin, color);
	for(int i = 0; i < piece.n_squares; i++) 
		mvwaddch(nextPieceWin, piece.yPiece[i] + 1, piece.xPiece[i] + 1, ' ');
		// +1 for borders
	wattroff(nextPieceWin, color);
	wrefresh(nextPieceWin);
}