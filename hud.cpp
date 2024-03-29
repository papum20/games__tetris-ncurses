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

	init_pair(10, COLOR_RED, COLOR_WHITE);		//SCORE
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);	//GAME OVER
}


//// SCORE

void Hud::updateFastScore() {
	score += FAST_SCORE;
}
void Hud::updateLineScore(int n) {
	lines += n;
	score += n * LINE_SCORE;
}
void Hud::drawScore() {
	wattron(scoreWin, COLOR_PAIR(10));
	fillWindow(scoreWin, COLOR_BLACK);
	mvwprintw(scoreWin, 1, 1, "%d", lines);
	mvwprintw(scoreWin, 2, 1, "%d", score);
	wrefresh(scoreWin);
	wattroff(scoreWin, COLOR_PAIR(10));
}
void Hud::resetScore() {
	score = 0;
	lines = 0;
}


//// FUNCTIONS

void Hud::drawPiece(piecePos piece, bool drawing) {
	chtype color = COLOR_PAIR(piece.color);
	if(drawing) wattron(nextPieceWin, color);
	for(int i = 0; i < piece.n_squares; i++)
		mvwaddch(nextPieceWin, piece.yPiece[i] + 1, piece.xPiece[i] + 1, ' ');
		// +1 for borders
	wattroff(nextPieceWin, color);
	wrefresh(nextPieceWin);
}


void Hud::drawGameOver(int xCenter, int yCenter) {
	WINDOW *gameOverWin = newwin(GAMEOVER_HEIGHT, GAMEOVER_WIDTH, yCenter - GAMEOVER_HEIGHT/2, xCenter - GAMEOVER_WIDTH/2);
	attr_t gameOverAttr = A_BOLD | COLOR_PAIR(11);
	wattron(gameOverWin, gameOverAttr);
	mvwprintw(gameOverWin, 0, 0, "GAME OVER  press R  to restart");
	wattroff(gameOverWin, gameOverAttr);
	wrefresh(gameOverWin);
	delwin(gameOverWin);
}