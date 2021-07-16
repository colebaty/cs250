boardTest: board.o boardTest.cpp
	g++-11 -g -DDEBUG -o boardTest boardTest.cpp board.o
	./boardTest

board.o: board.h board.cpp senet_constants.h
	g++-11 -g -DDEBUG -c board.h board.cpp senet_constants.h

clean:
	rm -rf *.o *.gch *Test