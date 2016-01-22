CC = gcc
CFLAGS = -g -Wall
DEPS = tree.h

default: tree
.PHONY : default
tree: tree.o main.o
        $(CC) $(CFLAGS) -o tree tree.o main.o

%.o: %.c $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)
        @echo $@" is generate."
.PHONY : clean
clean:
        -rm -f *.o tree
