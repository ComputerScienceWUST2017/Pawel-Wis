CC = g++
FLAGS = -c -Wall -Wextra

all: go

go: main.o Point.o
	$(CC) main.o Point.o -o a.out
	rm *.o *.gch

main.o:	main.cpp
	$(CC) $(FLAGS) main.cpp

Point.o: Point.h Point.cpp
	$(CC) $(FLAGS) Point.h Point.cpp

clean:
	rm *.o *.gch a.out
