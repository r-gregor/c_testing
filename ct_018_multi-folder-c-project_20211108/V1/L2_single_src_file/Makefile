CC=gcc
CFLAGS= -g -Wall
APP=main

all: dirs main

dirs:
	@if [ ! -d ./build ]; then echo "Creating ./build/..."; mkdir bin; fi;
	@if [ ! -d ./obj ]; then echo "Cretaing ./obj/..."; mkdir obj; fi;
	@if [ ! -d ./src ]; then echo "Cretaing ./src/..."; mkdir src; fi;

main: bin/$(APP)

bin/$(APP): obj/$(APP).o
	$(CC) $(CFLAGS) -o $@ $^

obj/$(APP).o: src/$(APP).c
	$(CC) -c -o $@ $^

clean:
	rm -r bin/* obj/*


