turnin: clean main.cpp 
	g++ -c -std=c++11 -g person.cpp
	g++ -c -std=c++11 -g staff.cpp 
	g++ -c -std=c++11 -g customer.cpp
	g++ -std=c++11 -g main.cpp -o ODUrentals person.o staff.o customer.o

dev: clean main.cpp person.o staff.o customer.o
	g++ -std=c++11 -DDEBUG -g -o ODUrentals main.cpp person.o staff.o customer.o

test: test.cpp person.o staff.o customer.o
	g++ -std=c++11 -DDEBUG -g -o runTests test.cpp person.o staff.o customer.o
	./runTests

person.o: person.h person.cpp
	g++ -c -std=c++11 -DDEBUG -g person.cpp

staff.o: staff.h staff.cpp person.o
	g++ -c -std=c++11 -DDEBUG -g staff.cpp 

customer.o: customer.h customer.cpp person.o
	g++ -c -std=c++11 -DDEBUG -g customer.cpp

clean:
	rm -rf runTests ODUrentals *.o *.dSYM

zip:
	zip -r Assg7_tbaty.zip . -i *.cpp *.h *.cbp 