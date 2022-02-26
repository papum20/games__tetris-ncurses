#include <curses.h>
#include "game.h"
using namespace std;




#define GAME_WIDTH 20
#define GAME_HEIGHT 20



int main()
{

	// CHECK IF FITS IN TERMINAL, COLORS...

	bool gameIsOn = true;

	initscr();

	// INIT GAME SCREEN
	Game gameWindow = Game(GAME_WIDTH, GAME_HEIGHT);
	gameWindow.createWindow();

	// INIT HUD

	// UPDATE
	while(gameIsOn)
	{

	}

	endwin();
}