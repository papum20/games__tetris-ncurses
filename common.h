#ifndef COMMON_H
#define COMMON_H


#include <stdlib.h>

//// PIECE

#define MAX_SQUARES 4

struct piecePos {
	int n_squares;
	int xPiece[MAX_SQUARES];
	int yPiece[MAX_SQUARES];
};



#endif