CC = g++
FLAGS = -c -Wall

all: go

go: main.o Shape.o
	$(CC) main.o Shape.o -o a.out
	rm *.o *.gch

main.o:	main.cpp
	$(CC) $(FLAGS) main.cpp

Shape.o: Shape.h Shape.cpp
	$(CC) $(FLAGS) Shape.h Shape.cpp

clean:
	rm *.o *.gch a.out
