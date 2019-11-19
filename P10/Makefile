CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: shelter

shelter: main.o mainwin.o shelter.o animal.o dog.o cat.o rabbit.o client.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o shelter.o animal.o dog.o cat.o rabbit.o client.o $(GTKFLAGS) -o shelter
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.cpp -o shelter.o
animal.o: animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.cpp -o animal.o
dog.o: dog.cpp *.h
	$(CXX) $(CXXFLAGS) -c dog.cpp -o dog.o
cat.o: cat.cpp *.h
	$(CXX) $(CXXFLAGS) -c cat.cpp -o cat.o
rabbit.o: rabbit.cpp *.h
	$(CXX) $(CXXFLAGS) -c rabbit.cpp -o rabbit.o
client.o: client.cpp *.h
	$(CXX) $(CXXFLAGS) -c client.cpp -o client.o
clean:
	rm -f *.o *.gch shelter


