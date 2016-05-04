all: FinalProject clean

FinalProject: main.o Maze.o
	g++ -std=c++11 main.o Maze.o -o FinalProject_EXE

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Maze.o: Maze.cpp
	g++ -c -std=c++11 Maze.cpp

clean:
	rm -f main.o
	rm -f Maze.o
