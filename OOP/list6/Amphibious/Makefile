CC = g++
FLAGS=-c -Wall

all: go

go: main.o ClassesStandard.o ClassesVirtual.o
	$(CC) main.o ClassesStandard.o ClassesVirtual.o -o a.out
	rm *.o *.gch

main.o : main.cpp
	$(CC) $(FLAGS) main.cpp

ClassesVirtual.o : ClassesVirtual.cpp ClassesVirtual.h
	$(CC) $(FLAGS) ClassesVirtual.h ClassesVirtual.cpp

ClassesStandard.o : ClassesStandard.cpp ClassesStandard.h
	$(CC) $(FLAGS) ClassesStandard.h ClassesStandard.cpp

clean:
	rm *.o *.gch
