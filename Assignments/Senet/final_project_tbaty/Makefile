refereeTest: referee.o refereeTest.cpp board.o player.o
	g++-11 -g -DDEBUG -o refereeTest refereeTest.cpp referee.o board.o player.o
	./refereeTest

playerTest: player.o referee.o board.o playerTest.cpp 
	g++ -std=c++11 -g -DDEBUG -o playerTest playerTest.cpp player.o board.o referee.o
	./playerTest

boardTest: board.o boardTest.cpp
	g++-11 -g -DDEBUG -o boardTest boardTest.cpp board.o
	./boardTest

board.o: board.h board.cpp senet_constants.h
	g++ -std=c++11 -g -DDEBUG -c board.cpp senet_constants.h

referee.o: referee.h referee.cpp senet_constants.h
	g++ -std=c++11 -g -DDEBUG -c referee.cpp senet_constants.h

player.o: player.h player.cpp 
	g++ -std=c++11 -g -DDEBUG -c player.cpp senet_constants.h

clean:
	rm -rf *.o *.gch *Test *.dSYM