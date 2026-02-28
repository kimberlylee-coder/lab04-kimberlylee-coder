FLAGS = -Wall -Werror
CPP = g++

all: examheap

heap.o: heap.cpp
	$(CPP) $(FLAGS) -c heap.cpp

examheap.o: examheap.cpp
	$(CPP) $(FLAGS) -c $^

examheap: heap.o examheap.o
	$(CPP) $(FLAGS) $^ -o $@