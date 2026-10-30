#for win
#CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./build/x86_64-w64-mingw32-gcc-11.1.0.exe
CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BUILD = ./build
SRC = ./src

SRCS = $(wildcard $(SRC)/*.c)
# PROGS = $(patsubst %.c,%,$(SRCS))
PROGS = $(SRCS:$(SRC)/%.c=%)

all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./build

%: $(SRC)/%.c $(SRC)/*.h
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $<

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $<

clean:
	$(RM) $(BUILD)/*

