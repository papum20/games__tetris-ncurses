#include "hud.h"



Hud::Hud(int xNextP, int yNextP, int xScore, int yScore) {
	nextPieceWin = newwin(NEXT_WIN_HEIGHT, NEXT_WIN_WIDTH, yNextP, xNextP);
	scoreWin = newwin(SCORE_WIN_HEIGHT, SCORE_WIN_WIDTH, yScore, xScore);
	box(nextPieceWin, 0, 0);
	box(scoreWin, 0, 0);
	wrefresh(nextPieceWin);
	wrefresh(scoreWin);

	score = 0;
	lines = 0;

	init_pair(10, COLOR_RED, COLOR_WHITE);
}


//// SCORE

	void Hud::updateFastScore() {
		score += FAST_SCORE;
	}
	void Hud::updateLineScore() {
		lines++;
		score += LINE_SCORE;
	}
	void Hud::drawScore() {
		wattron(scoreWin, COLOR_PAIR(10));
		fillWindow(scoreWin, COLOR_BLACK);
		mvwprintw(scoreWin, 1, 1, "%d", lines);
		mvwprintw(scoreWin, 2, 1, "%d", score);
		wrefresh(scoreWin);
		wattroff(scoreWin, COLOR_PAIR(10));
	}


//// FUNCTIONS

void Hud::drawPiece(piecePos piece, chtype color, bool drawing) {
	if(drawing) wattron(nextPieceWin, color);
	for(int i = 0; i < piece.n_squares; i++)
		mvwaddch(nextPieceWin, piece.yPiece[i] + 1, piece.xPiece[i] + 1, ' ');
		// +1 for borders
	wattroff(nextPieceWin, color);
	wrefresh(nextPieceWin);
}