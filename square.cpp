#include "square.h"



Square::Square(float x, float y) {
	this->x = x;
	this->y = y;
}


Square::Square() {
	this->x = 0;
	this->y = 0;
}


//// GET

float Square::getY() {
	return y;
}
float Square::getX() {
	return x;
}


//// FUNCTIONS

void Square::rotateAroundOrigin() {
	float tmpX = x;
	x = y;
	y = -tmpX;
}
void Square::unRotateAroundOrigin() {
	float tmpX = x;
	x = -y;
	y = tmpX;
}