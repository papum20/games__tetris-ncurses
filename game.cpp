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



void Game::checkCollision(Piece piece, int move[], int x_input, int y_input) {
	int pieceX[MAX_SQUARES], pieceY[MAX_SQUARES], n_sq;
	n_sq = piece.getSquares(pieceX, pieceY);
	move[0] = x_input, move[1] = y_input;

	for(int i = 0; i < n_sq; i++) {
		int new_x = pieceX[i] + x_input, new_y = pieceY[i] + y_input;
		if(new_x <= 0 || new_x >= width-1 || (new_y > 0 && full_squares[new_y][new_x])) move[0] = 0;
		if(new_y >= height-1 || (new_y > 0 && full_squares[new_y][new_x])) move[1] = 0;
	}
}



void Game::drawPiece(Piece piece, bool drawing) {
	if(drawing) wattron(gameWin, piece.getColor());

	int pieceX[MAX_SQUARES], pieceY[MAX_SQUARES], n_sq;
	n_sq = piece.getSquares(pieceX, pieceY);
	for(int i = 0; i < n_sq; i++) {
		mvwaddch(gameWin, pieceY[i], pieceX[i], ' ');
	}
	
	wattroff(gameWin, piece.getColor());
	wrefresh(gameWin);
}


bool Game::pieceToEnd(Piece piece) {
	int xPiece[MAX_SQUARES], yPiece[MAX_SQUARES], nSquares;
	nSquares = piece.getSquares(xPiece, yPiece);

	bool isToEnd = false;
	int i = 0;
	while(i < MAX_SQUARES) {
		if(yPiece[i] == height - 2) isToEnd = true;
		i++;
	}
	return isToEnd;
}


void Game::addToGrid(Piece piece) {
	int piece_x[MAX_SQUARES], piece_y[MAX_SQUARES], n_squares;
	n_squares = piece.getSquares(piece_x, piece_y);

	for(int i = 0; i < n_squares; i++)
		full_squares[piece_y[i]][piece_x[i]] = true;
}