#include "hud.h"



Hud::Hud(int xNextP, int yNextP, int xScore, int yScore) {
	nextPieceWin = newwin(4, 6, yNextP, xNextP);
	scoreWin = newwin(4, 6, yScore, xScore);
	box(nextPieceWin, 0, 0);
	box(scoreWin, 0, 0);
}

Hud::Hud() {
	
}

//Hud::Hud(int xNextP, int yNextP) {
	//nextPieceWin = newwin(4, 6, yNextP, xNextP);
	//scoreWin = newwin(4, 6, yNextP + 4, xNextP);
//	Hud(xNextP, yNextP, xNextP, yNextP + 4);
//}



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