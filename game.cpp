#include "game.h"

Game::Game(int w, int h, int bgc) {
	width = w;
	height = h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) full_squares[i][j] = false;
	createWindow();
	bg_color = bgc;
}


void Game::createWindow() {
	int x, y;
	getmaxyx(stdscr, y, x);
	gameWin = newwin(height, width, y/4, x/4);
	box(gameWin, 0, 0);
	wrefresh(gameWin);
}

WINDOW *Game::getWindow() {
	return gameWin;
}



char Game::checkCollision(Piece piece, int x_input, int y_input) {
	int pieceX[MAX_SQUARES], pieceY[MAX_SQUARES], n_sq;
	n_sq = piece.getSquares(pieceX, pieceY);

	bool x_collide = false, y_collide = false;
	int i = 0;
	while(i < n_sq) {
		int new_x = pieceX[i] + x_input, new_y = pieceY[i] + y_input;
		if(new_x < 0 || new_x >= width) {
			x_collide = true;
			if(full_squares[new_y]) y_collide = true;
		}
		else if(full_squares[new_y]) y_collide = true;
	}

	if(x_collide && y_collide) return 'b';
	else if(x_collide) return 'x';
	else if(y_collide) return 'y';
	else return 'n';
}



void Game::drawPiece(Piece piece, bool drawing) {
	if(drawing) attron(piece.getColor());
	else attron(COLOR_PAIR(bg_color));

	int pieceX[MAX_SQUARES], pieceY[MAX_SQUARES], n_sq;
	n_sq = piece.getSquares(pieceX, pieceY);
	for(int i = 0; i < n_sq; i++) {
		mvwaddch(gameWin, pieceY[i], pieceX[i], ' ');
	}
	
	if(drawing) attroff(piece.getColor());
	else attroff(COLOR_PAIR(bg_color));
}
