#include <curses.h>
#include <ctime>

#define DFLT_TIME 1000
#define MAX_TIMERS 20


class InputManager {
	protected:
		int x, y;
		int time;	//milliseconds
		WINDOW *inputWin;
		//TIMER
		double startTime[MAX_TIMERS];
		float currentTime[MAX_TIMERS];
		float clockDuration[MAX_TIMERS];

		void init();
	public:
		InputManager(int winX, int winY, int t = DFLT_TIME);
		void getInput();
		//gets input and sets input variables
		int getX();
		int getY();
		//TIMER
		//id < MAX_TIMERS
		void timerInit(int id, int duration = 0);
		//initializes timer variables for timer identified by id
		bool timerCount(int id);
		//increments timer and returns if timer ended (requires timerInit first) for id
};