CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: store

debug: CXXFLAGS += -g
debug: store

rebuild: clean store

store: mainwin.o customer.o desktop.o main.o options.o order.o store.o entrydialog.o *.h
	$(CXX) $(CXXFLAGS) mainwin.o customer.o desktop.o main.o store.o options.o order.o entrydialog.o $(GTKFLAGS) -o store

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp -o entrydialog.o

clean:
	-rm -f *.o *.gch *~ store
