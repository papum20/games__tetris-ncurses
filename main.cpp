#include <ctime>
#include "game.h"
#include "inputManager.h"
using namespace std;




#define GAME_WIDTH 20
#define GAME_HEIGHT 20



int main()
{
	srand(time(NULL));

	// CHECK IF FITS IN TERMINAL, COLORS...

	bool gameIsOn = true;

	initscr();

	// INIT GAME
	Game gameScreen = Game(GAME_WIDTH, GAME_HEIGHT, 0);
	Piece pieceController = Piece(GAME_WIDTH / 2, GAME_HEIGHT + 5);
	pieceController.newPiece();
	InputManager inputManager = InputManager();
	inputManager.init(gameScreen.getWindow());

	// INIT HUD

	// UPDATE
	while(gameIsOn)
	{
		//CHECK INPUT
		inputManager.getInput(gameScreen.getWindow());
		int new_coord[2];
		gameScreen.checkCollision(pieceController, new_coord, inputManager.getX(), 1 + inputManager.getY());
		//MOVE
		gameScreen.drawPiece(pieceController, false);
		pieceController.move(new_coord[0], new_coord[1]);
		gameScreen.drawPiece(pieceController, true);
		//CHECK IF GOT TO END
		if(new_coord[1] == 0) {
			gameScreen.addToGrid(pieceController);
			pieceController.newPiece();
		}
	}

	endwin();
}