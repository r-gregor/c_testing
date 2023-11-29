CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BIN = ./bin

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BIN)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./bin

v2: progbar_v2.c
	$(CC) $(CFLAGS) -o $(BIN)/progbar_v2 progbar_v2.c -lcurl

$(BIN)/%: %.c
	$(CC) $(CFLAGS)  -o $@ $< -lcurl

clean:
	$(RM) $(PROGS)
