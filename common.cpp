#include "common.h"


void fillWindow(WINDOW *win, chtype color) {
	wattron(win, color);
	for(int y = 1; y < getmaxy(win) - 1; y++) {
		wmove(win, y, 1);
		for(int x = 1; x < getmaxx(win) - 1; x++)
			waddch(win, ' ');
	}
	wattroff(win, color);
}