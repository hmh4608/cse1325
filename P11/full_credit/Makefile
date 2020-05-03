CXXFLAGS += --std=c++17

all: main
	
debug: CXXFLAGS += -g
debug: main	

rebuild: clean main
	
main: main.o cart.o item.o *.h
	$(CXX) $(CXXFLAGS) main.o cart.o item.o -o main

	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) -c cart.cpp -o cart.o
item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) -c item.cpp -o item.o
	
clean:
	-rm -f *.o *.gch *~ main
