#include "game.h"

Game::Game(int start_x, int start_y, int w, int h, int bgc) {
	width = w;
	height = h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) full_squares[i][j] = false;
	createWindow(start_x, start_y);
	bg_color = bgc;
}


void Game::createWindow(int start_x, int start_y) {
	int x, y;
	getmaxyx(stdscr, y, x);
	gameWin = newwin(height, width, start_y, start_x);
	box(gameWin, 0, 0);
	wrefresh(gameWin);
}

WINDOW *Game::getWindow() {
	return gameWin;
}



//// FUNCTIONS


bool Game::checkCollision(piecePos piece) {
	bool collides = false;
	for(int i = 0; i < piece.n_squares; i++) {
		int new_x = piece.xPiece[i], new_y = piece.yPiece[i];
		if(new_x <= 0 || new_x >= width-1)					collides = true;
		else if(new_y >= height-1) 							collides = true;
		else if(new_y > 0 && full_squares[new_y][new_x])	collides = true;
	}
	return collides;
}



void Game::drawPiece(piecePos piece, chtype color, bool drawing) {
	if(drawing) wattron(gameWin, color);
	for(int i = 0; i < piece.n_squares; i++)
		if(piece.yPiece[i] > 0) mvwaddch(gameWin, piece.yPiece[i], piece.xPiece[i], ' ');
	
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




//// GRID

void Game::addToGrid(piecePos piece) {
	for(int i = 0; i < piece.n_squares; i++)
		full_squares[piece.yPiece[i]][piece.xPiece[i]] = true;
}

int Game::checkLine(int line) {
	bool full = true;
	bool empty = true;
	for(int i = 1; i < width - 1; i++) {
		if(!full_squares[line][i]) full = false;
		else empty = false;
	}
	if(full) return 1;
	else if(empty) return -1;
	else return 0;
}

void Game::moveLine() {
	int check, move = 0, y = height - 1;
	do {
		check = checkLine(y);
		if(check == 1) move++;
		if(move > 0 && y < height - 1) {
			for(int x = 1; x < width - 1; x++) {
				full_squares[y][x] = false;
				full_squares[y-1][x] = true;
				
			}
		}
	} while(y > 0 && (check != -1 || move != 0));
}