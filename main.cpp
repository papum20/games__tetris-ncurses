#include <ctime>
#include "game.h"
#include "inputManager.h"
using namespace std;


#define GAME_HEIGHT 20



int main()
{
	srand(time(NULL));

	// CHECK IF FITS IN TERMINAL, COLORS...

	bool gameIsOn = true;

	initscr();
	start_color();

	// INIT GAME
	//Game gameScreen = Game(GAME_WIDTH, GAME_HEIGHT, 0);
	//Piece pieceController = Piece(GAME_WIDTH / 2, 6);
	//pieceController.newPiece();
	//InputManager inputManager = InputManager(1000);
	//inputManager.init(gameScreen.getWindow());

	// INIT HUD
init_pair(10, COLOR_BLUE, COLOR_WHITE);
attron(COLOR_PAIR(10));
mvprintw(0, 0, "%d", 3);
//attroff(COLOR_PAIR(10));
refresh();


	// UPDATE
	while(gameIsOn)
	{
	/*
		//CHECK INPUT
		inputManager.getInput(gameScreen.getWindow());
	init_pair(10, COLOR_BLUE, COLOR_WHITE);
	attron(COLOR_PAIR(10));
	mvprintw(0, 0, "%d", inputManager.getX());
	printw(" %d", inputManager.getY());
	move(1, 0);
	int sqx[MAX_SQUARES], sqy[MAX_SQUARES], n_sq;
	n_sq = pieceController.getSquares(sqx, sqy);
	for(int i = 0; i < n_sq; i++) {
		printw("%d %d-", sqx[i], sqy[i]);
	}
		refresh();/*
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
*/
	}


	endwin();
}