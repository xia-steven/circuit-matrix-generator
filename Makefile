# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++17 -O3

circuit: circuit.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

example:
	./circuit <conductance_test.txt

clean:
	rm -f circuit output.txt circuit.m
