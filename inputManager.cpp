#include "inputManager.h"


InputManager::InputManager(int winX, int winY, int t) {
	x = 0;
	y = 0;
	time = t;
	inputWin = newwin(3, 20, winY-2, winX);
	init();
}

void InputManager::init() {
	noecho();					//doesn't print input
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
void InputManager::setY(int y) {
	x = 0;
	this->y = y;
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

void InputManager::timerInit(int id, float duration) {
	startTime[id] = (double)clock() / CLOCKS_PER_SEC;
	currentTime[id] = startTime[id];
	clockDuration[id] = duration;
}

bool InputManager::timerCount(int id) {
	currentTime[id] = (double)clock() / CLOCKS_PER_SEC;
if(id==0) mvwprintw(inputWin, 1,0, "%f %f", currentTime[id] - startTime[id], clockDuration[id]);
else if(id==1) mvwprintw(inputWin, 2,0, "%f %f", currentTime[id] - startTime[id], clockDuration[id]);
	return (currentTime[id] - startTime[id] >= clockDuration[id]);
}