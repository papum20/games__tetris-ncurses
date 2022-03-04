#include "inputManager.h"


InputManager::InputManager(int winX, int winY, int t) {
	x = 0;
	y = 0;
	time = t;
	inputWin = newwin(1, 30, winY, winX);
	init();
}

void InputManager::init() {
	noecho();					//doesn't print input
	keypad(inputWin, true);		//can use special keys
	cbreak();					//can use ctrl+X
	wtimeout(inputWin, time);	//waits milliseconds for input
	curs_set(0);				//no cursor
}

//// GET
int InputManager::getX() {
	return x;
}
int InputManager::getY() {
	return y;
}
void InputManager::setY() {
	y = 1;
}
bool InputManager::rotateInput() {
	return rotate;
}

//// FUNCTIONS



void InputManager::getInput() {
	//CLEAR INPUT
	x = 0;
	y = 0;
	rotate = false;
	//GET INPUT
	int input = mvwgetch(inputWin, 0, 0);
mvwprintw(inputWin, 0, 2, "%d %d %d %d,%d\t", KEY_LEFT, KEY_RIGHT, KEY_DOWN, KEY_UP, input);
wrefresh(inputWin);
	if(input == KEY_LEFT) x = -1;
	else if(input == KEY_RIGHT) x = 1;
	else if(input == KEY_DOWN) y = 1;
	else if(input == KEY_UP) rotate = true;
}


//// TIMER

void InputManager::timerInit(int id, float duration) {
	startTime[id] = (double)clock() / CLOCKS_PER_SEC;
	currentTime[id] = startTime[id];
	clockDuration[id] = duration;
}

bool InputManager::timerCount(int id) {
	currentTime[id] = (double)clock() / CLOCKS_PER_SEC;
	return (currentTime[id] - startTime[id] >= clockDuration[id]);
}