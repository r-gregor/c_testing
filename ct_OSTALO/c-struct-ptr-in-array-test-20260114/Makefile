# for win
# CC=/c/Users/gregor.redelonghi/majstaf_en/majprogs_en/mingw64/bin/x86_64-w64-mingw32-gcc-11.1.0.exe
# info: comments must not be indented or they get parsed by shell ...
CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BIN = ./bin

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BIN)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./bin

$(BIN)/%: %.c *.h
	$(CC) $(CFLAGS) -o $@ $<
#	$(CC) $(CFLAGS) -o $@ $< -lncurses

$(BIN)/%: %.c
	$(CC) $(CFLAGS) -o $@ $<
#	$(CC) $(CFLAGS) -o $@ $< -lncurses

clean:
	$(RM) $(BIN)/*
