TARGET=game
MODULES=game.o ioutil.o Board.o Piece.o Pawn.o King.o Queen.o Bishop.o Knight.o Rook.o helper.h
MODULETEST =test_Board.o Board.o Piece.o Pawn.o King.o Queen.o Bishop.o Knight.o Rook.o helper.h
MODULE_TEST_PIECE =test_Pieces.o Board.o Piece.o Pawn.o King.o Queen.o Bishop.o Knight.o Rook.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lgtest_main
TESTS=test_Board
TESTS_PIECE=test_Pieces
GCOVFILE=test_Board
GCOVFILE_PIECE=test_Pieces

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
	/bin/rm -f *~ *.o $(TARGET) $(TESTS_PIECE) $(TESTS) *.gcda *.gcov *.gcno

all:   clean $(TARGET) $(TESTS_PIECE) $(TESTS)



$(TARGET).o: $(TARGET).cpp Board.h Piece.h 
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TARGET).cpp

ioutil.o : ioutil.cpp ioutil.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c ioutil.cpp		

Piece.o : Piece.cpp Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Piece.cpp	

Pawn.o : Pawn.cpp Pawn.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Pawn.cpp	

King.o : King.cpp King.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c King.cpp	

Queen.o : Queen.cpp Queen.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Queen.cpp	

Bishop.o : Bishop.cpp Bishop.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Bishop.cpp	

Knight.o : Knight.cpp Knight.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Knight.cpp	

Rook.o : Rook.cpp Rook.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c Rook.cpp	



Board.o: Board.cpp Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS)  -c Board.cpp

$(TESTS).o: $(TESTS).cpp Board.h Piece.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS).cpp

$(TESTS_PIECE).o: $(TESTS_PIECE).cpp Piece.h Board.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS_PIECE).cpp

