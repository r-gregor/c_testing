CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BIN = ./bin

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BIN)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./bin

$(BIN)/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BIN)/*

test:
	/usr/bin/valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s $(PROGS)

