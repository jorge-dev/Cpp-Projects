TARGET=game
MODULES=game.o Board.o Piece.o
MODULETEST =test_Board.o Board.o Piece.h
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lgtest_main
TESTS=test_Board
GCOVFILE=test_Board

$(TARGET): $(MODULES)
	g++  $(GTFLAGS) $(MODULES) $(GCOVFLAGS) -o $(TARGET)

$(TESTS): $(MODULETEST) 
	g++  $(GTFLAGS) $(GCOVFLAGS) $(MODULETEST) -o $(TESTS)
	$(TESTS)	
	gcov $(GCOVFILE).cpp 2> /dev/null | grep -A 1 $(GCOVFILE).cpp
clean:
	/bin/rm -f *~ *.o $(TARGET) $(TESTS) *.gcda *.gcov *.gcno

all:   clean $(TARGET) $(TESTS) 


$(TARGET).o: $(TARGET).cpp Board.h Piece.h 
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TARGET).cpp

Piece.o : Piece.cpp Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Piece.cpp	

Board.o: Board.cpp Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS)  -c Board.cpp

$(TESTS).o: $(TESTS).cpp Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS).cpp

