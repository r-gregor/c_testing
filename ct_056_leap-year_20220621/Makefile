CC = gcc
# CC= /c/Users/gregor.redelonghi/majstaf_en/majprogs_en/mingw./build/gcc.exe
CFLAGS = -g -Wall
RM = rm -v
BUILD = ./build

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BUILD)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./build

$(BUILD)/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) ./build/*
