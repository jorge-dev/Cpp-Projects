TARGET=game
MODULES=game.o Board.o Piece.o helper.h ioutil.o
MODULETEST =test_Board.o Board.o Piece.o
MODULE_TEST_PIECE =test_Piece.o Board.o Piece.o 
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lgtest_main
TESTS=test_Board
TESTS_PIECE=test_Piece
GCOVFILE=test_Board
GCOVFILE_PIECE=test_Piece

$(TARGET): $(MODULES)
	g++  $(GTFLAGS) $(MODULES) $(GCOVFLAGS) -o $(TARGET)


$(TESTS): $(MODULETEST) 
	g++  $(GTFLAGS) $(GCOVFLAGS) $(MODULETEST) -o $(TESTS)
	$(TESTS)	
	gcov $(GCOVFILE).cpp 2> /dev/null | grep -A 1 $(GCOVFILE).cpp

$(TESTS_PIECE): $(MODULE_TEST_PIECE) 
	g++  $(GTFLAGS) $(GCOVFLAGS) $(MODULE_TEST_PIECE) -o $(TESTS_PIECE)
	$(TESTS_PIECE)	
	gcov $(TESTS_PIECE).cpp 2> /dev/null | grep -A 1 $(TESTS_PIECE).cpp

clean:
	/bin/rm -f *~ *.o $(TARGET)  $(TESTS) $(TESTS_PIECE) *.gcda *.gcov *.gcno

all:   clean $(TARGET) $(TESTS) $(TESTS_PIECE)    



$(TARGET).o: $(TARGET).cpp Board.h Piece.h 
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TARGET).cpp

Piece.o : Piece.cpp Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Piece.cpp	

ioutil.o : ioutil.cpp Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c ioutil.cpp	


Board.o: Board.cpp Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS)  -c Board.cpp

$(TESTS).o: $(TESTS).cpp Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS).cpp

$(TESTS_PIECE).o: $(TESTS_PIECE).cpp Piece.h Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS_PIECE).cpp

