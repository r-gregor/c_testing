# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./build/x86_64-w64-mingw32-gcc-11.1.0.exe
CC = gcc
CFLAGS = -g -Wall
EXE=example example_w_freelist
RM = rm -v
BUILD = ./build

all: newbindir $(EXE)

newbindir:
	@mkdir -p ./build

%.o: %.c objpool.h
	$(CC) $(CFLAGS) -c $< -o $@

example: example.c objpool.o
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

example_w_freelist: example.c objpool_w_freelist.o
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

clean:
	$(RM) $(BUILD)/*
	$(RM) ./*.o
