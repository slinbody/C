CC = gcc
CFLAGS = -g -Wall

default: tree

tree: tree.o main.o
        $(CC) $(CFLAGS) -o tree tree.o main.o

main.o: main.c tree.h
        $(CC) $(CFLAGS) -c main.c

tree.o: tree.c tree.h
        $(CC) $(CFLAGS) -c tree.c
        @echo "tree.o OK!"
clean:
        $(RM) main.o tree.o tree
