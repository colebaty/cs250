# turnin: main.cpp person.o staff.o customer.o
# 	g++ -std=c++11 -g main.cpp person.o staff.o customer.o

dev: main.cpp person.o staff.o customer.o
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
	rm -f runTests ODUrentals *.o