#include "inputManager.h"


InputManager::InputManager(int t) {
	x = 0;
	y = 0;
	time = t;
}

void InputManager::init(WINDOW *win) {
	noecho();			//doesn't print input
	keypad(win, true);	//can use special keys
	cbreak();			//can use ctrl+X
	timeout(time);		//waits milliseconds for input
}

//// GET
int InputManager::getX() {
	return x;
}
int InputManager::getY() {
	return y;
}

//// FUNCTIONS



void InputManager::getInput(WINDOW *win) {
	//CLEAR INPUT
	x = 0;
	y = 0;
	//GET INPUT
	char input = (char)wgetch(win);
	if(input == KEY_LEFT) x = -1;
	else if(input == KEY_RIGHT) x = 1;
	else if(input == KEY_DOWN) y = 1;
}