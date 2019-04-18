TESTS=teams
MODULES=a4p1.o HockeyList.o ioutil.o 
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
#GTFLAGS=-lgtest -lgtest_main


a4p1.o: a4p1.cpp  HockeyList.h ioutil.h  
	g++ $(CPPFLAGS) -g -c a4p1.cpp


$(TESTS): $(MODULES)
	g++ $(GTFLAGS) $(MODULES) -o $(TESTS)


clean:
	/bin/rm -f  $(TESTS) *# *~ 

all:	clean $(TESTS)









