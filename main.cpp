#include <iostream>
#include <ctime>
#include "inputManager.h"
#include "piece.h"
#include "hud.h"
#include "common.h"
using namespace std;


#define FALL_RATE .8
#define REFRESH_RATE 1. / 30


int main()
{

	// CHECK IF FITS IN TERMINAL, COLORS...

	bool gameIsOn = true;

	initscr();
	start_color();
	srand(time(NULL));

	// INIT GAME
//	int start_x = GAME_HEIGHT / 4;
//	int start_y = GAME_WIDTH / 4;
	int start_x = min(getmaxx(stdscr) - GAME_WIDTH, getmaxx(stdscr) / 4);
	int start_y = min(getmaxy(stdscr) - GAME_HEIGHT, getmaxy(stdscr) / 4);

	Game gameScreen = Game(start_x, start_y, GAME_WIDTH, GAME_HEIGHT, 0);
	InputManager inputManager = InputManager(start_x, start_y - 1);

	Piece pieceController = Piece();
	pieceController.newPiece();
	Piece nextPiece = Piece();
	nextPiece.newPiece();
	Piece::defineColors();
	
	Hud hudManager = Hud(start_x - NEXT_WIN_WIDTH, start_y);
	hudManager.drawPiece(nextPiece.getNormalSquares(), nextPiece.getColor(), true);
//DEBUG WINDOW
//WINDOW *debugWin = newwin(6, GAME_WIDTH, start_y + GAME_HEIGHT, start_x);
//keypad(debugWin, true);
//box(debugWin, 0, 0);
//wrefresh(debugWin);



	// UPDATE
	bool fastInput = false;
	inputManager.timerInit(0, FALL_RATE);				// TIMER 0 = FALL TIME
	while(gameIsOn)
	{
		if(!inputManager.timerCount(0)) {				// IF: INPUT MOVEMENT
			inputManager.timerInit(1, REFRESH_RATE);	// TIMER 1 = INPUT TIME
			while(!inputManager.timerCount(1));
			inputManager.getInput();
			if(inputManager.getY() == 1) fastInput = true;
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
		if(inputManager.getY() != newY) {			//if blocked on y
			gameScreen.addToGrid(pieceController.getSquares());
			gameScreen.moveLine();

			hudManager.drawPiece(nextPiece.getNormalSquares(), nextPiece.getColor(), false);
			pieceController = nextPiece;
			nextPiece.newPiece();
			hudManager.drawPiece(nextPiece.getNormalSquares(), nextPiece.getColor(), true);
		}
		else if(fastInput)
			hudManager.updateFastScore();

		//UPDATE HUD
		hudManager.drawScore();
		fastInput = false;

	}

	endwin();
}
