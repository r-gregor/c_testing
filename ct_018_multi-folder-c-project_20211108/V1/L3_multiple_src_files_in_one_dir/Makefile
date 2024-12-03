CC = gcc
CFLAGS = -g -Wall
RM = rm -v

# all: newbindir main
all: main

# newbindir:
# 	@if [ ! -d ./build ]; then echo "Creating ./build/..."; mkdir bin; fi;
# 	@if [ ! -d ./obj ]; then echo "Cretaing ./obj/..."; mkdir obj; fi;
# 	@if [ ! -d ./src ]; then echo "Cretaing ./src/..."; mkdir src; fi;

main: main.o myfunc.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $^

clean:
	rm *.o
