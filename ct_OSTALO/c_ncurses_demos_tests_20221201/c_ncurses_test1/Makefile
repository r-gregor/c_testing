# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw64/bin/x86_64-w64-mingw32-gcc-11.1.0.exe
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
	$(CC) $(CFLAGS) -o $@ $< -lncurses

clean:
	$(RM) $(BIN)/*
