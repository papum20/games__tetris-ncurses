#include "game.h"

Game::Game(int w, int h, int bgc) {
	width = w;
	height = h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) full_squares[i][j] = false;
	createWindow();
	bg_color = bgc;

	start_color();
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



void Game::checkCollision(Piece piece, int out[], int x_input, int y_input) {
	int pieceX[MAX_SQUARES], pieceY[MAX_SQUARES], n_sq;
	n_sq = piece.getSquares(pieceX, pieceY);

	int i = 0;
	while(i < n_sq) {
		int new_x = pieceX[i] + x_input, new_y = pieceY[i] + y_input, fast_y = pieceY[i] + 1;
		if(new_x <= 0 || new_x >= width-1) out[0] = 0;
		if(new_y >= height-1 || full_squares[new_y]) out[1] = 0;
		else if(fast_y >= height-1 || full_squares[fast_y]) out[1] = 1;
	}
}



void Game::drawPiece(Piece piece, bool drawing) {
	if(drawing) attron(piece.getColor());
	//else attron(COLOR_PAIR(bg_color));

	int pieceX[MAX_SQUARES], pieceY[MAX_SQUARES], n_sq;
	n_sq = piece.getSquares(pieceX, pieceY);
	for(int i = 0; i < n_sq; i++) {
		mvwaddch(gameWin, pieceY[i], pieceX[i], ' ');
	}
	
	if(drawing) attroff(piece.getColor());
	//else attroff(COLOR_PAIR(bg_color));
	wrefresh(gameWin);
}


void Game::addToGrid(Piece piece) {
	int piece_x[MAX_SQUARES], piece_y[MAX_SQUARES], n_squares;
	n_squares = piece.getSquares(piece_x, piece_y);

	for(int i = 0; i < n_squares; i++)
		full_squares[piece_y[i]][piece_x[i]] = true;
}