#Makefile for Coin

CXXFLAGS += --std=c++17

all: test coin

logger: CXXFLAGS += -DLOGGER
logger: coin test

rebuild: clean coin

coin: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin
test: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o test

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch

clean:
	rm -f *.o *.gch ~* a.out test coin
