CC = g++
FLAGS=-c -Wall

all: go

go: main.o Bicycle.o 
	$(CC) main.o Bicycle.o -o a.out
	rm *.o *.gch

main.o : main.cpp
	$(CC) $(FLAGS) main.cpp

Bicycle.o : Bicycle.cpp Bicycle.h
	$(CC) $(FLAGS) Bicycle.h Bicycle.cpp

clean:
	rm *.o *.gch

