SHELL := /bin/bash
CXXFLAGS += --std=c++17

all: timep timet

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

timet: threads FORCE
	@printf '\nWith threads:\n'
	time (./threads $(call args,4 10000000) > primes_threads.txt)
threads: threads.cpp
	 $(CXX) $(CXXFLAGS) -pthread threads.cpp -o threads
timep: primes FORCE
	@printf 'Without threads:\n'
	time (./primes $(call args,1 10000000) > primes.txt)
primes: primes.cpp
	 $(CXX) $(CXXFLAGS) -pthread primes.cpp -o primes
clean:
	-rm -f *.o *.gch *~ a.out primes threads primes*.txt
FORCE:
	@printf '\nCalculating primes\n==================\n'
%:
	@:
args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`
