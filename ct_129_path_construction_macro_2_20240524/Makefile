# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./bin/x86_64-w64-mingw32-gcc-11.1.0.exe
CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BIN = ./bin

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BIN)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p $(BIN)

$(BIN)/%: %.c ubuild.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BIN)/*
