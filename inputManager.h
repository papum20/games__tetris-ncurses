#include <curses.h>
#include <ctime>

#define DFLT_TIME 0
#define MAX_TIMERS 20



// ALWAYS 1 INPUT AT A TIME

class InputManager {
	protected:
		int x, y;
		int time;	//milliseconds
		WINDOW *inputWin;
		//TIMER
		float startTime[MAX_TIMERS];
		float currentTime[MAX_TIMERS];
		float clockDuration[MAX_TIMERS];

		void init();
	public:
		InputManager(int winX, int winY, int t = DFLT_TIME);
		void getInput();
		//gets input and sets input variables
		int getX();
		int getY();
		void setY(int y);
		//TIMER
		//id < MAX_TIMERS
		void timerInit(int id, float duration = 0);
		//initializes timer variables for timer identified by id
		bool timerCount(int id);
		//increments timer and returns if timer ended (requires timerInit first) for id
};