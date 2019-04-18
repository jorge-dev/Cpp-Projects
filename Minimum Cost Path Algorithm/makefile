TESTS=matrix
MODULES= a3_v4.o 

CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GTFLAGS=-lgtest -lgtest_main


a3_v4.o: a3_v4.cpp 
	g++ $(CPPFLAGS) -g -c a3_v4.cpp


$(TESTS): $(MODULES)
	g++ $(MODULES) -o $(TESTS)


clean:
	/bin/rm -f  $(TESTS) *# *~ *.o

all:	clean $(TESTS)









