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
int refresh = 0;
	// UPDATE
	inputManager.timerInit(0, FALL_RATE);				// TIMER 0 = FALL TIME
	while(gameIsOn)
	{
		if(!inputManager.timerCount(0)) {		// IF: INPUT MOVEMENT
			inputManager.timerInit(1, REFRESH_RATE);	// TIMER 1 = INPUT TIME
			while(!inputManager.timerCount(1));
			inputManager.getInput();
refresh++;
		}
		else {											// ELSE: FALL MOVEMENT
			inputManager.setY(1);
			inputManager.timerInit(0, FALL_RATE);
//			turn = 0;
refresh = 0;
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

mvwprintw(debugWin, 1,1, "%d,\t%d   ", turn++, refresh);
mvwprintw(debugWin, 2,1, "%d,%d, %d,%d", inputManager.getX(), inputManager.getY(), new_coord[0], new_coord[1]);
wrefresh(debugWin);
	}
	

	
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




	endwin();
}