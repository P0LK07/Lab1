CC = gcc
CFLAGS =-c -Wall

all: launch

launch: main.o matrix.o
	$(CC) main.o matrix.o -o lab1

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o 

matrix.o: matrix.c
	$(CC) $(CFLAGS) matrix.c -o matrix.o