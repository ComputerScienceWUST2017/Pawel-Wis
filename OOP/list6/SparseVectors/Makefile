CC = g++
FLAGS=-c -Wall

all: go

go: main.o SparseVectors.o
	$(CC) main.o SparseVectors.o -o a.out
	rm *.o *.gch

main.o : main.cpp
	$(CC) $(FLAGS) main.cpp

SparseVectors.o : SparseVectors.cpp SparseVectors.h
	$(CC) $(FLAGS) SparseVectors.h SparseVectors.cpp

clean:
	rm *.o *.gch
