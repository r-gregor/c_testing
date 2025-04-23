#for win
#CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./build/x86_64-w64-mingw32-gcc-11.1.0.exe
CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BIN = ./bin
SRC = ./src

SRCS = $(wildcard $(SRC)/*.c)
# PROGS = $(patsubst %.c,%,$(SRCS))
PROGS = $(SRCS:$(SRC)/%.c=%)

all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./bin

%: $(SRC)/%.c $(SRC)/*.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

clean:
	$(RM) $(BIN)/*

