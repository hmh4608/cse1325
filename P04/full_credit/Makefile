#Makefile for Coin

CXXFLAGS += --std=c++17

all: coin

logger: CXXFLAGS += -DLOGGER
logger: coin

rebuild: clean coin

coin: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin

coin.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch

clean:
	rm -f *.o *.gch ~* a.out coin
