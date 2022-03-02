#include "game.h"
#include "inputManager.h"
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
	int start_x = GAME_HEIGHT / 4;
	int start_y = GAME_WIDTH / 4;

	Game gameScreen = Game(start_x, start_y, GAME_WIDTH, GAME_HEIGHT, 0);
	Piece pieceController = Piece(GAME_WIDTH / 2, 6);
	pieceController.newPiece();
	InputManager inputManager = InputManager(start_x, start_y - 1);

//DEBUG WINDOW
//WINDOW *debugWin = newwin(6, GAME_WIDTH, start_y + GAME_HEIGHT, start_x);
//keypad(debugWin, true);
//box(debugWin, 0, 0);
//wrefresh(debugWin);

	// INIT HUD



	// UPDATE
	inputManager.timerInit(0, FALL_RATE);				// TIMER 0 = FALL TIME
	while(gameIsOn)
	{
		if(!inputManager.timerCount(0)) {		// IF: INPUT MOVEMENT
			inputManager.timerInit(1, REFRESH_RATE);	// TIMER 1 = INPUT TIME
			while(!inputManager.timerCount(1));
			inputManager.getInput();
		}
		else {											// ELSE: FALL MOVEMENT
			inputManager.setY(1);
			inputManager.timerInit(0, FALL_RATE);
		}

		//MOVE
		int new_coord[2];
		gameScreen.checkCollision(pieceController, new_coord, inputManager.getX(), inputManager.getY());

		gameScreen.drawPiece(pieceController, false);
		pieceController.move(new_coord[0], new_coord[1]);
		gameScreen.drawPiece(pieceController, true);
		
		//CHECK IF GOT TO END
		if(inputManager.getY() != new_coord[1]) {		//if blocked on y
			gameScreen.addToGrid(pieceController);
			pieceController.newPiece();
		}

	}


	endwin();
}