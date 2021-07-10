turnin: main.cpp employee.o
	g++ --std=c++11 -g -o genTestData main.cpp employee.o 

genTestData: main.cpp employee.o
	g++ --std=c++11 -g -DDEBUG -o genTestData main.cpp employee.o 

test: findDriver.cpp employee.o
	g++ --std=c++11 -g -DDEBUG -o findDriver findDriver.cpp employee.o

clean:
	rm -f *.o *.gch genTestData *.zip

employee.o: employee.h employee.cpp 
	g++ --std=c++11 -g -DDEBUG -c employee.cpp

zip:
	zip -r Assg6A_tbaty.zip . -i *.cpp *.h *.cbp -x find*