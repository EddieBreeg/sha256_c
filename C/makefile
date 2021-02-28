SDIR = src
CFLAGS = -I $(SDIR) -Wall
BIN = bin

all: $(BIN)
	make test

test: $(SDIR)/sha256.c tests/test.c
	gcc $(SDIR)/sha256.c tests/test.c $(CFLAGS) -o $(BIN)/test

$(BIN):
	mkdir bin