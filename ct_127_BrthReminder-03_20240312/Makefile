# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./build/x86_64-w64-mingw32-gcc-11.1.0.exe
CC = gcc
CFLAGS = -g -Wall
RM = rm -v
BUILD = ./build

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,$(BUILD)/%,$(SRCS))



all: newbindir $(PROGS)

newbindir:
	@mkdir -p ./build
	@cp -vn ROJSTNIDNEVI.txt ./build/

$(BUILD)/%: %.c *.h
	@cp -vn ROJSTNIDNEVI.txt ./build/
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BUILD)/*
