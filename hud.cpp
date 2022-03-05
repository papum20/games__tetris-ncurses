#include "hud.h"



Hud::Hud(int xNextP, int yNextP, int xScore, int yScore) {
	nextPieceWin = newwin(NEXT_WIN_HEIGHT, NEXT_WIN_WIDTH, yNextP, xNextP - NEXT_WIN_WIDTH);
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
	//get min x,y to use as translation vector so it's drawed in top-left corner
	int xT = piece.xPiece[0], yT = piece.yPiece[0];
	for(int i = 1; i < MAX_SQUARES; i++) {
		if(piece.xPiece[i] < xT) xT = piece.xPiece[i];
		if(piece.yPiece[i] < yT) yT = piece.yPiece[i];
	}
	//add border
	xT--;
	yT--;

	//draw
	if(drawing) wattron(nextPieceWin, color);
	for(int i = 0; i < piece.n_squares; i++) {
		if(piece.yPiece[i] > 0) mvwaddch(nextPieceWin, piece.yPiece[i] - yT, piece.xPiece[i] - xT, ' ');
	}
	wattroff(nextPieceWin, color);
	wrefresh(nextPieceWin);
}