# turnin: main.cpp 
# 	g++ -c -std=c++11 -g person.cpp 
# 	g++ -c -std=c++11 -g board.cpp
# 	g++ -std=c++11 -g -o almostChess main.cpp player.o board.o

# dev: clean main.cpp person.o board.o
# 	g++ -std=c++11 -DDEBUG -g -o almostChess main.cpp person.o staff.o customer.o

test: test.cpp player.o 
	g++ -std=c++11 -DDEBUG -g -o runTests test.cpp player.o board.o
	./runTests

player.o: player.h player.cpp board.o
	g++ -c -std=c++11 -DDEBUG -g player.cpp

board.o: board.h board.cpp 
	g++ -c -std=c++11 -DDEBUG -g board.cpp 

clean:
	rm -rf runTests almostChess *.o *.dSYM *.zip

zip:
	zip -r Assg8_tbaty.zip . -i *.cpp *.h *.cbp Makefile -x test*
