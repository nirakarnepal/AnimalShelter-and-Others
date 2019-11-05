CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: animals 

animals: main-gui.o mainwin.o *.h
	$(CXX) $(CXXFLAGS) main-gui.o mainwin.o $(GTKFLAGS) -o animals
main-gui.o: main-gui.cpp *.h
	$(CXX) $(CXXFLAGS) -c main-gui.cpp $(GTKFLAGS) -o main-gui.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

clean:
	rm -f *.o *.gch a.out sweets sweets-cli


