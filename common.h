#ifndef COMMON_H
#define COMMON_H


#include <stdlib.h>
#include <curses.h>


/// GAME
#define GAME_WIDTH 12		//10+2
#define GAME_HEIGHT 20		//18+2

//// PIECE
#define MAX_SQUARES 4

struct piecePos {
	int n_squares;
	int xPiece[MAX_SQUARES];
	int yPiece[MAX_SQUARES];
};

//// HUD
#define NEXT_WIN_WIDTH 6
#define NEXT_WIN_HEIGHT 4
#define SCORE_WIN_WIDTH 6
#define SCORE_WIN_HEIGHT 4


//// ALL

void fillWindow(WINDOW *win, chtype color);



#endif