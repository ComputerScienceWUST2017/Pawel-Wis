CC = g++
FLAGS=-c -Wall


all: go

go: main.o ArabianNumbers.o Rectangle.o
	$(CC) main.o ArabianNumbers.o Rectangle.o -o a.out
	rm -rf *.o *.gch

main.o : main.cpp
	$(CC) $(FLAGS) main.cpp

ArabianNumbers.o : ArabianNumbers.cpp ArabianNumbers.h
	$(CC) $(FLAGS) ArabianNumbers.h ArabianNumbers.cpp

Rectangle.o : Rectangle.cpp Rectangle.h
	$(CC) $(FLAGS) Rectangle.h Rectangle.cpp

clean:
	rm -rf *.o *.gch
