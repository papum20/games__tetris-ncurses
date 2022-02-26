#include <curses.h>
#include <ctime>
#include "game.h"
using namespace std;




#define GAME_WIDTH 20
#define GAME_HEIGHT 20



int main()
{
	srand(time(NULL));

	// CHECK IF FITS IN TERMINAL, COLORS...

	bool gameIsOn = true;

	initscr();

	// INIT GAME SCREEN
	Game gameScreen = Game(GAME_WIDTH, GAME_HEIGHT, 0);


	// INIT HUD

	// UPDATE
	while(gameIsOn)
	{

	}

	endwin();
}