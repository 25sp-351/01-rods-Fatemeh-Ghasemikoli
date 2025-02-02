CC = clang
CFLAGS = -g -Wall

all: main

main: main.o
    $(CC) $(CFLAGS) -o main main.o

main.o: main.c
    $(CC) $(CFLAGS) -c 01-rods.c

clean:
    rm -f *.o main
