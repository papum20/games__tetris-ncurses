#include <curses.h>




class InputManager {
	protected:
		int x, y;
		int time;	//milliseconds
	public:
		InputManager(int t);
		void init(WINDOW *win);
		void getInput(WINDOW *win);
};