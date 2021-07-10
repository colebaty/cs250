all: clean
	g++-11 -o battleship *.cpp

debug: 
	rm -rf battleship *.o *.dSYM
	g++-11 -DDEBUG -o battleship -g *.cpp >> cmplerr.log
	
clean:
	$(RM) battleship *.o
