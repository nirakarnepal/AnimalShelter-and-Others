CXXFLAGS = --std=c++17

averages: main.o average.o
	$(CXX) $(CXXFLAGS) main.o average.o -o averages

average: main.o average.o
	$(CXX) $(CXXFLAGS) main.o average.o -o averages

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

average.o: average.cpp
	$(CXX) $(CXXFLAGS) -c average.cpp -o average.o

clean:
	rm -f *.o *.gch ~* a.out averages
