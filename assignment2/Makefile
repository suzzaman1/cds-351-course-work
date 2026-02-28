# Compiler
CXX = g++

# CDS-351 recommended compiler flags:
CXXFLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic -Wshadow

# Phony targets to avoid filename conflicts
.PHONY: all clean

all: askname.x type_limits.x namespace.x

askname.x: askname.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

type_limits.x: type_limits.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

namespace.x: namespace.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o *.x
