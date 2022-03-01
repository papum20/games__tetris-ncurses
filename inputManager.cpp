#include "inputManager.h"


InputManager::InputManager(int winX, int winY, int t) {
	x = 0;
	y = 0;
	time = t;
	inputWin = newwin(1, 20, winY, winX);
	init();
}

void InputManager::init() {
	//noecho();					//doesn't print input
	keypad(inputWin, true);		//can use special keys
	cbreak();					//can use ctrl+X
	wtimeout(inputWin, time);	//waits milliseconds for input
	curs_set(1);				//no cursor
}

//// GET
int InputManager::getX() {
	return x;
}
int InputManager::getY() {
	return y;
}

//// FUNCTIONS



void InputManager::getInput() {
	//CLEAR INPUT
	x = 0;
	y = 0;
	//GET INPUT
	int input = mvwgetch(inputWin, 0, 0);
	if(input == KEY_LEFT) x = -1;
	else if(input == KEY_RIGHT) x = 1;
	else if(input == KEY_DOWN) y = 1;
}


//// TIMER

void InputManager::timerInit(int id, int duration) {
	currentTime[id] = 0;
	startTime[id] = clock() / CLOCKS_PER_SEC;
	clockDuration[id] = duration;
}

bool InputManager::timerCount(int id) {
	currentTime[id] += clock() / CLOCKS_PER_SEC;
	return (currentTime[id] - startTime[id] >= clockDuration[id]);
}