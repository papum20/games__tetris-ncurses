tetris: main.o game.o hud.o inputManager.o piece.o square.o
	g++ main.o game.o hud.o inputManager.o piece.o square.o -lncurses -o tetris

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp game.h
	g++ -c game.cpp

hud.o: hud.cpp hud.h
	g++ -c hud.cpp

inputManager.o: inputManager.cpp inputManager.h
	g++ -c inputManager.cpp

piece.o: piece.cpp piece.h
	g++ -c piece.cpp

square.o: square.cpp square.h
	g++ -c square.cpp


clean:
	rm *.o tetris tetris.exe