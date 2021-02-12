CC=g++
CXXFLAGS=-std=c++11 -pedantic -Wall -Wextra 

customCal: Date.o Calendar.o main.o 
	$(CC) Date.o main.o Calendar.o -o customCal $(CXXFLAGS)

Date.o: Date.cpp Date.h
	$(CC) -c Date.cpp $(CXXFLAGS)

Calendar.o: Calendar.h Calendar.cpp 
	$(CC) -c Calendar.cpp $(CXXFLAGS)

main.o: main.cpp Date.h Calendar.h
	$(CC) -c main.cpp $(CXXFLAGS)

clean:
	rm -f *.o customCal
