#include <ncurses/curses.h>

#define DFLT_TIME (float)1 / 60


class InputManager {
	protected:
		int x, y;
		int time;	//milliseconds
	public:
		InputManager(int t = DFLT_TIME);
		void init(WINDOW *win);
		//to be called with game window
		void getInput(WINDOW *win);
		//gets input and sets input variables
		int getX();
		int getY();
};