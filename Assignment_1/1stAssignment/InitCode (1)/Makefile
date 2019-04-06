main.o: main.cpp core.h
	g++ -c main.cpp
core.o: core.cpp core.h
	g++  -c core.cpp
framecode.o: framecode.cpp core.h
	g++ -c framecode.cpp
all: core.o main.o framecode.o
	g++ main.o core.o framecode.o -o main
clean:
	rm -f *.o main
