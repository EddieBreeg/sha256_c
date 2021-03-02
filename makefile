SDIR = src
CFLAGS = -I $(SDIR) -Wall -g
BIN = bin

all: $(BIN)
	make test1
	make test2
	make test3

test1: $(SDIR)/sha256.c tests/test.c
	gcc $(SDIR)/sha256.c tests/test.c $(CFLAGS) -o $(BIN)/test

test2: $(SDIR)/sha256.c tests/test2.c
	gcc $(SDIR)/sha256.c tests/test2.c $(CFLAGS) -o $(BIN)/test2

test3: $(SDIR)/sha256.c tests/test3.c
	gcc $(SDIR)/sha256.c tests/test3.c $(CFLAGS) -o $(BIN)/test3

$(BIN):
	mkdir bin