#include "square.h"



Square::Square(int x, int y) {
	this->x = x;
	this->y = y;
}


Square::Square() {
	this->x = 0;
	this->y = 0;
}



int Square::getY() {
	return y;
}
int Square::getX() {
	return x;
}
