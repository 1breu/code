CC=g++
CXXFLAGS=-std=c++11 -pedantic -Wall -Wextra

largeSums: largeSums.o
	$(CC) largeSums.o -o largeSums $(CXXFLAGS)

largeSums.o: largeSums.cpp linkedList.h unorderedLinkedList.h
	$(CC) -c largeSums.cpp $(CXXFLAGS)

clean:
	rm -f *.o largeSums
