CC = gcc
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
	$(RM) $(BUILD)/*

test:
	/us./build/valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s $(PROGS)

