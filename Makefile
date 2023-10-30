CC=gcc
CFLAGS_RELEASE=-I. -pedantic -Wall -O3
CFLAGS_DEBUG=-I. -pedantic -g
SOURCES=main.c src/parse.c
PROGRAM=prog

release:
	$(CC) -o $(PROGRAM) $(CFLAGS_RELEASE) $(SOURCES)

debug:
	$(CC) -o $(PROGRAM) $(CFLAGS_DEBUG) $(SOURCES)

clean:
	rm -f $(PROGRAM)
