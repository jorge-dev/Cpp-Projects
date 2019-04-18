TARGET=a4p2
MODULES=a4p2.o HockeyList.o ioutil.o
MODULETEST =test_HockeyList.o HockeyList.o HockeyList.h
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lgtest_main
TESTS=test_HockeyList
GCOVFILE=test_HockeyList

$(TARGET): $(MODULES)
	g++  $(GTFLAGS) $(MODULES) $(GCOVFLAGS) -o $(TARGET)

$(TESTS): $(MODULETEST) 
	g++  $(GTFLAGS) $(GCOVFLAGS) $(MODULETEST) -o $(TESTS)
	$(TESTS)	
	gcov $(GCOVFILE).cpp 2> /dev/null | grep -A 1 $(GCOVFILE).cpp
clean:
	/bin/rm -f *~ *.o $(TARGET) $(TESTS) *.gcda *.gcov *.gcno

all:   clean $(TARGET) $(TESTS) 


$(TARGET).o: $(TARGET).cpp HockeyList.h ioutil.h 
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TARGET).cpp

ioutil.o : ioutil.cpp ioutil.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c ioutil.cpp	

HockeyList.o: HockeyList.cpp HockeyList.h
	g++ $(CPPFLAGS) $(GCOVFLAGS)  -c HockeyList.cpp

$(TESTS).o: $(TESTS).cpp HockeyList.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS).cpp

