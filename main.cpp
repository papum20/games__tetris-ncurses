#include "game.h"
#include "inputManager.h"
using namespace std;


#define GAME_HEIGHT 20
#define FALL_RATE 0.8
//#define REFRESH_RATE (float)1 / 30


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
	WINDOW *debugWin = newwin(6, GAME_WIDTH, start_y + GAME_HEIGHT, start_x);
	keypad(debugWin, true);
	box(debugWin, 0, 0);
	wrefresh(debugWin);

	// INIT HUD
//init_pair(10, COLOR_BLUE, COLOR_WHITE);
//wattron(gameScreen.getWindow(), COLOR_PAIR(10));
//mvwprintw(gameScreen.getWindow(), 2, 2, "%d", 33);
////attroff(COLOR_PAIR(10));
//refresh();
//wrefresh(gameScreen.getWindow());


int turn = 0;
bool last_line = false;
	// UPDATE
	while(gameIsOn)
	{

		// INPUT MOVEMENT
		inputManager.timerInit(0, FALL_RATE);
		do {
			//CHECK INPUT
			inputManager.getInput();
			//MOVE
			int new_coord[2];
			gameScreen.checkCollision(pieceController, new_coord, inputManager.getX(), inputManager.getY());
	//DEBUG
	mvwprintw(debugWin, 4, 1, "%d,%d", new_coord[0], new_coord[1]);
	wprintw(debugWin, "-%d", pieceController.getColor());
	wrefresh(debugWin);
			gameScreen.drawPiece(pieceController, false);
			pieceController.move(new_coord[0], new_coord[1]);
			gameScreen.drawPiece(pieceController, true);
			
			//CHECK IF GOT TO END
			if(gameScreen.pieceToEnd(pieceController)) {
				if(!last_line) last_line = true;
				else {
					gameScreen.addToGrid(pieceController);
					pieceController.newPiece();
					last_line = false;
				}
			}
			else last_line = false;

		} while(!inputManager.timerCount(0));

	
		//FALL

	
////DEBUG
//mvwprintw(debugWin, 1, 10, "%d", turn++);
//
//init_pair(10, COLOR_BLUE, COLOR_WHITE);
//wattron(debugWin, COLOR_PAIR(10));
//mvwprintw(debugWin, 1, 1, "%d,%d ", inputManager.getX(), inputManager.getY());
//wmove(debugWin, 2, 1);
//int sqx[MAX_SQUARES], sqy[MAX_SQUARES], n_sq;
//n_sq = pieceController.getSquares(sqx, sqy);
//for(int i = 0; i < n_sq; i++) {
//	wprintw(debugWin, "%d %d,", sqx[i], sqy[i]);
//}
//wrefresh(debugWin);


	}


	endwin();
}