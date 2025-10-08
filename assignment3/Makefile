# Compiler
CXX = g++

# CDS-351 recommended compiler flags:
CXXFLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic -Wshadow

# Phony targets to avoid filename conflicts
.PHONY: all clean

all: test_copy_floats.x grains_rice.x spell_days.x

test_copy_floats.x: test_copy_floats.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

grains_rice.x: grains_rice.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

spell_days.x: spell_days.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o *.x
