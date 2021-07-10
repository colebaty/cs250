turnin: main.cpp employee.o
	g++ -std=c++11 -g -o genResults main.cpp employee.o 

genResults: main.cpp employee.o
	g++ -std=c++11 -g -DDEBUG -o genResults main.cpp employee.o

clean:
	rm -f *.o *.gch genTestData *.zip

employee.o: employee.h employee.cpp 
	g++ -std=c++11 -g -DDEBUG -c employee.cpp

zip:
	zip -r Assg6B_tbaty.zip . -i *.cpp *.h *.cbp *.txt -x employeereport*