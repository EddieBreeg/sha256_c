SDIR = src
CFLAGS = -I $(SDIR) -Wall -g
BIN = bin

all: $(BIN)
	make test
	make test2

test: $(SDIR)/sha256.c tests/test.c
	gcc $(SDIR)/sha256.c tests/test.c $(CFLAGS) -o $(BIN)/test

test2: $(SDIR)/sha256.c tests/test2.c
	gcc $(SDIR)/sha256.c tests/test2.c $(CFLAGS) -o $(BIN)/test2

$(BIN):
	mkdir bin