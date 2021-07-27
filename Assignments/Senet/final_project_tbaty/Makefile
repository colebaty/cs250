main: main.cpp referee.o board.o player.o
	g++ -std=c++11 -g main.cpp referee.o board.o player.o

senet: senet.cpp referee.o board.o player.o
	g++ -std=c++11 -g -DDEBUG -o senet senet.cpp referee.o board.o player.o

trapSquareProtectionTest: referee.o trapSquareProtectionTest.cpp board.o player.o
	g++ -std=c++11 -g -DDEBUG -o trapSquareProtectionTest trapSquareProtectionTest.cpp referee.o board.o player.o
	
endgameTest: referee.o endgameTest.cpp board.o player.o
	g++ -std=c++11 -g -DDEBUG -o endgameTest endgameTest.cpp referee.o board.o player.o
	
noMoveTest: referee.o noMoveTest.cpp board.o player.o
	g++ -std=c++11 -g -DDEBUG -o noMoveTest noMoveTest.cpp referee.o board.o player.o
	
turnTest: referee.o turnTest.cpp board.o player.o
	g++ -std=c++11 -g -DDEBUG -o turnTest turnTest.cpp referee.o board.o player.o

refereeTest: referee.o refereeTest.cpp board.o player.o
	g++ -std=c++11 -g -DDEBUG -o refereeTest refereeTest.cpp referee.o board.o player.o
	./refereeTest

playerTest: player.o referee.o board.o playerTest.cpp 
	g++ -std=c++11 -g -DDEBUG -o playerTest playerTest.cpp player.o board.o referee.o
	./playerTest

boardTest: board.o boardTest.cpp
	g++ -std=c++11 -g -DDEBUG -o boardTest boardTest.cpp board.o
	./boardTest

board.o: board.h board.cpp senet_constants.h
	g++ -std=c++11 -g -DDEBUG -c board.cpp senet_constants.h

referee.o: referee.h referee.cpp senet_constants.h
	g++ -std=c++11 -g -DDEBUG -c referee.cpp senet_constants.h

player.o: player.h player.cpp 
	g++ -std=c++11 -g -DDEBUG -c player.cpp senet_constants.h

clean:
	rm -rf *.zip *.o *.gch *Test *.dSYM

zip:
	zip -r final_project_tbaty.zip . -i *.cpp *.h *.cbp Makefile -x *Test* Makefile