#include "game.h"

Game::Game(int start_x, int start_y, int w, int h, int bgc) {
	width = w;
	height = h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) full_squares[i][j] = false;
	createWindow(start_x, start_y);
	bg_color = bgc;

	start_color();
}


void Game::createWindow(int start_x, int start_y) {
	int x, y;
	getmaxyx(stdscr, y, x);
	gameWin = newwin(height, width, start_x, start_y);
	box(gameWin, 0, 0);
	wrefresh(gameWin);
}

WINDOW *Game::getWindow() {
	return gameWin;
}



bool Game::checkCollision(piecePos piece) {
	bool collides = false;
	for(int i = 0; i < piece.n_squares; i++) {
		int new_x = piece.xPiece[i], new_y = piece.yPiece[i];
		if(new_x <= 0 || new_x >= width-1 || (new_y > 0 && full_squares[new_y][new_x])) collides = true;
		else if(new_y >= height-1 || (new_y > 0 && full_squares[new_y][new_x])) collides = true;
	}
	return collides;
}



void Game::drawPiece(piecePos piece, chtype color, bool drawing) {
	if(drawing) wattron(gameWin, color);

	for(int i = 0; i < piece.n_squares; i++) {
		mvwaddch(gameWin, piece.yPiece[i], piece.xPiece[i], ' ');
	}
	
	wattroff(gameWin, color);
	wrefresh(gameWin);
}


//bool Game::pieceToEnd(Piece piece) {
//	int xPiece[MAX_SQUARES], yPiece[MAX_SQUARES], nSquares;
//	nSquares = piece.getSquares(xPiece, yPiece);
//
//	bool isToEnd = false;
//	int i = 0;
//	while(i < MAX_SQUARES) {
//		if(yPiece[i] == height - 2) isToEnd = true;
//		i++;
//	}
//	return isToEnd;
//}


void Game::addToGrid(piecePos piece) {
	for(int i = 0; i < piece.n_squares; i++)
		full_squares[piece.yPiece[i]][piece.xPiece[i]] = true;
}