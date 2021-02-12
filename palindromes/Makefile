CC=g++
CXXFLAGS=-std=c++11 -pedantic -Wall -Wextra

palindromes: palindromes.o
	$(CC) palindromes.o -o palindromes $(CXXFLAGS)

palindromes.o: palindromes.cpp linkedStack.h linkedQueue.h
	$(CC) -c palindromes.cpp $(CXXFLAGS)

clean:
	rm -f *.o palindromes
