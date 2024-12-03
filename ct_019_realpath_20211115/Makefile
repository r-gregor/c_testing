CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BUILD = ./build
TARGET = myrealpathtest

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BUILD)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./build

$(BUILD)/%: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	$(RM) $(PROGS)

