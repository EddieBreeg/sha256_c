SDIR = src
CFLAGS = -I $(SDIR) -Wall
BIN = bin

all: $(BIN)
	make main
	make test1
	make test2
	make test3

main: $(SDIR)/sha256.c $(SDIR)/main.c
	gcc $(SDIR)/sha256.c $(SDIR)/main.c $(CFLAGS) -o $(BIN)/sha256

test1: $(SDIR)/sha256.c tests/test.c
	gcc $(SDIR)/sha256.c tests/test.c $(CFLAGS) -o $(BIN)/test

test2: $(SDIR)/sha256.c tests/test2.c
	gcc $(SDIR)/sha256.c tests/test2.c $(CFLAGS) -o $(BIN)/test2

test3: $(SDIR)/sha256.c tests/test3.c
	gcc $(SDIR)/sha256.c tests/test3.c $(CFLAGS) -o $(BIN)/test3

$(BIN):
	mkdir bin