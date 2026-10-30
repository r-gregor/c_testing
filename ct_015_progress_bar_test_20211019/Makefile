CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BUILD = ./build

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BUILD)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./build

v2: progbar_v2.c
	$(CC) $(CFLAGS) -o $(BUILD)/progbar_v2 progbar_v2.c -lcurl

$(BUILD)/%: %.c
	$(CC) $(CFLAGS)  -o $@ $< -lcurl

clean:
	$(RM) $(PROGS)
