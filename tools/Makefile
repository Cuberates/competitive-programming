.PHONY: all test clean

all: debug_test.out

test: debug_test.out

debug_test.out: debug_test.cpp debug.hpp
	$(CXX) -std=c++2b -Wall -Wextra -pedantic debug_test.cpp -o debug_test.out

clean:
	rm -f debug_test.out
