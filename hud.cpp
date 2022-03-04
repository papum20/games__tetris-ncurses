#include "hud.h"



Hud::Hud(int xNextP, int yNextP, int xScore, int yScore) {
	nextPieceWin = newwin(4, 6, yNextP, xNextP);
	scoreWin = newwin(4, 6, yScore, xScore);
}

Hud::Hud(int xNextP, int yNextP) {
	nextPieceWin = newwin(4, 6, yNextP, xNextP);
	scoreWin = newwin(4, 6, yNextP + 4, xNextP);
}



void drawPiece(piecePos piece, chtype color, bool drawing) {

}