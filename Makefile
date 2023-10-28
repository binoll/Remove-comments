CC=gcc
CFLAGS=-I. -pedantic -O3
SOURCES=main.c src/parse.c
PROGRAM=prog

all:
	$(CC) -o $(PROGRAM) $(CFLAGS) $(SOURCES)

clean:
	rm -f $(PROGRAM)
