CC = gcc
# CC= /c/Users/gregor.redelonghi/majstaf_en/majprogs_en/mingw64/bin/gcc.exe
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
	$(RM) ./bin/*
