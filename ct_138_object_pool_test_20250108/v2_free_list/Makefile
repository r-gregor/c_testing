# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./bin/x86_64-w64-mingw32-gcc-11.1.0.exe
CC = gcc
CFLAGS = -g -Wall
EXE=example example_w_freelist
RM = rm -v
BIN = ./bin

all: newbindir $(EXE)

newbindir:
	@mkdir -p ./bin

%.o: %.c objpool.h
	$(CC) $(CFLAGS) -c $< -o $@

example: example.c objpool.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

example_w_freelist: example.c objpool_w_freelist.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

clean:
	$(RM) $(BIN)/*
	$(RM) ./*.o
