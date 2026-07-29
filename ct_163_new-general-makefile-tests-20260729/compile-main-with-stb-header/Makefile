# for win
# CC=/c/Users/gregor.redelonghi/majstaf_en/majprogs_en/mingw64/bin/x86_64-w64-mingw32-gcc-11.1.0.exe
# info: comments must not be indented or they get parsed by shell ...
CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BIN = ./bin
SRC = ./src
LBRS = 

SRCS = $(wildcard $(SRC)/*.c)
MAIN = myshinynewprogram2

all: newbindir MAIN

newbindir:
	@mkdir -p ./bin

MAIN: $(SCRS)
	gcc -Wall -o bin/$(MAIN) $(SRCS) $(LBRS)
#	$(CC) $(CFLAGS) -o $@ $< -lncurses

clean:
	$(RM) $(BIN)/*
