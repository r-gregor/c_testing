# CC=clang
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw6./build/x86_64-w64-mingw32-gcc-11.1.0.exe
CC=gcc
CFLAGS=-g -Wall
OBJS=main.o matrix.o ui.o
# LDFLAGS="-I C:\Users\gregor.redelonghi\majstaf\majprogs\cygwin64\usr\include -L C:\Users\gregor.redelonghi\majstaf\majprogs\cygwin64\lib -lncurses"
LDFLAGS="-nlcurses"


all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf ./*.o main

