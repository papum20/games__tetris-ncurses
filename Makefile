tetris: main.o game.o square.o piece.o inputManager.o
	g++ main.o game.o square.o piece.o inputManager.o -lncurses -o tetris

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp game.h
	g++ -c game.cpp

square.o: square.cpp square.h
	g++ -c square.cpp

piece.o: piece.cpp piece.h
	g++ -c piece.cpp

inputManager.o: inputManager.cpp inputManager.h
	g++ -c inputManager.cpp


clean:
	rm *.o tetris tetris.exe