playerTest: player.o playerTest.cpp
	g++-11 -g -DDEBUG -o playerTest playerTest.cpp player.o
	./playerTest

boardTest: board.o boardTest.cpp
	g++-11 -g -DDEBUG -o boardTest boardTest.cpp board.o
	./boardTest

board.o: board.h board.cpp senet_constants.h
	g++-11 -g -DDEBUG -c board.cpp senet_constants.h

player.o: player.h player.cpp senet_constants.h
	g++-11 -g -DDEBUG -c player.cpp senet_constants.h

clean:
	rm -rf *.o *.gch *Test *.dSYM