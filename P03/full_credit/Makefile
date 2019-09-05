CXXFLAGS = --std=c++17

lines: main.o line.o
	$(CXX) $(CXXFLAGS) main.o line.o -o lines

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

line.o: line.cpp
	$(CXX) $(CXXFLAGS) -c line.cpp -o line.o

clean:
	rm -f *.o *.gch ~* a.out lines
