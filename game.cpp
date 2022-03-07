#include "game.h"

Game::Game(int start_x, int start_y, int w, int h, int bgc) {
	width = w;
	height = h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) full_squares[i][j] = EMPTY_SQUARE;
	createWindow(start_x, start_y);
	bg_color = bgc;
}


void Game::createWindow(int start_x, int start_y) {
	int x, y;
	getmaxyx(stdscr, y, x);
	gameWin = newwin(height, width, start_y, start_x);
	box(gameWin, 0, 0);
	wrefresh(gameWin);
debugWin = newwin(height, width, start_y, start_x + width);
}

WINDOW *Game::getWindow() {
	return gameWin;
}



//// FUNCTIONS


bool Game::checkCollision(piecePos piece) {
	bool collides = false;
	for(int i = 0; i < piece.n_squares; i++) {
		int new_x = piece.xPiece[i], new_y = piece.yPiece[i];
		if(new_x <= 0 || new_x >= width-1)									collides = true;
		else if(new_y >= height-1) 											collides = true;
		else if(new_y > 0 && full_squares[new_y][new_x] != EMPTY_SQUARE)	collides = true;
	}
	return collides;
}



void Game::drawPiece(piecePos piece, bool drawing) {
	chtype color = COLOR_PAIR(piece.color);
	if(drawing) wattron(gameWin, color);
	for(int i = 0; i < piece.n_squares; i++)
		if(piece.yPiece[i] > 0) mvwaddch(gameWin, piece.yPiece[i], piece.xPiece[i], ' ');
	
	wattroff(gameWin, color);
	wrefresh(gameWin);
}


//// GRID

void Game::addToGrid(piecePos piece) {
	for(int i = 0; i < piece.n_squares; i++)
		full_squares[piece.yPiece[i]][piece.xPiece[i]] = piece.color;
}


int Game::checkLine(int line) {
	bool full = true;
	bool empty = true;
	for(int i = 1; i < width - 1; i++) {
		if(full_squares[line][i] == EMPTY_SQUARE) full = false;
		else empty = false;
	}
	if(full) return 1;
	else if(empty) return -1;
	else return 0;
}

void Game::moveLine() {
	int check, move = 0, y = height - 2;
//InputManager im(10,1);
	do {
		check = checkLine(y);
		if(check == 1) {					//if full line
			move++;
			mvwchgat(gameWin, y, 1, width - 2, A_NORMAL, EMPTY_SQUARE, NULL);			//erase line

		}
		else if(check == 0 && move > 0) {	//if line not full nor empty
			mvwchgat(gameWin, y, 1, width - 2, A_NORMAL, EMPTY_SQUARE, NULL);			//erase line
			for(int x = 1; x < width - 1; x++) {
				full_squares[y+move][x] = full_squares[y][x];
				mvwchgat(gameWin, y + move, x, 1, A_NORMAL, full_squares[y][x], NULL);	//move line down
				full_squares[y][x] = EMPTY_SQUARE;
			}
		}
		y--;
	} while(y > 0 && check != -1);
	wrefresh(gameWin);
}




void Game::debug() {
for(int y = 0; y < height; y++) {
	for(int x = 0; x < width; x++) {
		mvwprintw(debugWin, y, x, "%d", full_squares[y][x] == EMPTY_SQUARE);
	}
}
wrefresh(debugWin);
}