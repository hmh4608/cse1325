CXXFLAGS += --std=c++17

all: store

debug: CXXFLAGS += -g
debug: store

rebuild: clean store

store: customer.o desktop.o main.o options.o order.o store.o *.h
	$(CXX) $(CXXFLAGS) customer.o desktop.o main.o store.o options.o order.o -o store

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp
desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp

clean:
	-rm -f *.o *.gch *~ store
