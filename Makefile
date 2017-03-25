CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall
objects = slow.o
EXECUTABLE = slow

all: $(EXECUTABLE)

$(EXECUTABLE): $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o $(EXECUTABLE)

slow.o: slow.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm $(objects)
	-rm $(EXECUTABLE)

.PHONY: all clean
