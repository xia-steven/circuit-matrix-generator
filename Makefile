# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++17 -O3

circuit: circuit.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f circuit output.txt circuit.m
