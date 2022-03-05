#include <iostream>
#include "inputManager.h"
#include "piece.h"
#include "hud.h"
using namespace std;


#define GAME_HEIGHT 20
#define FALL_RATE 1.
#define REFRESH_RATE 1. / 30


int main()
{
	srand(time(NULL));

	// CHECK IF FITS IN TERMINAL, COLORS...

	bool gameIsOn = true;

	initscr();

	
	// INIT GAME
	int start_x = min(getmaxx(stdscr) - GAME_WIDTH, getmaxx(stdscr) / 4);
	int start_y = min(getmaxy(stdscr) - GAME_HEIGHT, getmaxy(stdscr) / 4);
WINDOW *w = newwin(20,20,1,1);
wprintw(w, "%d %d", start_x, start_y);
wrefresh(w);
wgetch(w);

	Game gameScreen = Game(start_x, start_y, GAME_WIDTH, GAME_HEIGHT, 0);
return 0;
	InputManager inputManager = InputManager(start_x, start_y - 1);

	Piece pieceController = Piece();
	pieceController.newPiece();
	//Piece nextPiece = Piece();
	//nextPiece.newPiece();
	
//WINDOW *w = newwin(1,1,1,1);

//wgetch(w);
//return 0;
//	Hud hudManager = Hud(start_x, start_y);
//	hudManager.drawPiece(nextPiece.getSquares(), nextPiece.getColor(), true);

//DEBUG WINDOW
//WINDOW *debugWin = newwin(6, GAME_WIDTH, start_y + GAME_HEIGHT, start_x);
//keypad(debugWin, true);
//box(debugWin, 0, 0);
//wrefresh(debugWin);



	// UPDATE
	inputManager.timerInit(0, FALL_RATE);				// TIMER 0 = FALL TIME
	while(gameIsOn)
	{
		if(!inputManager.timerCount(0)) {				// IF: INPUT MOVEMENT
			inputManager.timerInit(1, REFRESH_RATE);	// TIMER 1 = INPUT TIME
			while(!inputManager.timerCount(1));
			inputManager.getInput();
		}
		else {											// ELSE: FALL MOVEMENT
			inputManager.setY();
			inputManager.timerInit(0, FALL_RATE);
		}


		int newX, newY;
		gameScreen.drawPiece(pieceController.getSquares(), pieceController.getColor(), false);

		//ROTATE
		if(inputManager.rotateInput()) {
			pieceController.rotate(gameScreen);
		}
		//MOVE
		if(!gameScreen.checkCollision(pieceController.getSquares(inputManager.getX(), inputManager.getY()) )) {
			newX = inputManager.getX();
			newY = inputManager.getY();
		} else {
			newX = 0;
			newY = 0;
		}
		pieceController.move(newX, newY);
	
		gameScreen.drawPiece(pieceController.getSquares(), pieceController.getColor(), true);


		//CHECK IF GOT TO END
/*		if(inputManager.getY() != newY) {			//if blocked on y
			gameScreen.addToGrid(pieceController.getSquares());
			hudManager.drawPiece(pieceController.getSquares(), pieceController.getColor(), false);
			pieceController = nextPiece;
			nextPiece.newPiece();
			hudManager.drawPiece(nextPiece.getSquares(), nextPiece.getColor(), true);
		}*/

	}

	endwin();
}
