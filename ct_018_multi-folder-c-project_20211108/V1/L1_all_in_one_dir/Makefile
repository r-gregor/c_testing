SHELL=/us./bin/bash
CC=gcc
CFLAGS= -g -Wall
APP=main

all: dirs main

dirs:
	@echo $(SHELL)
	@if [ ! -d ./bin ]; then echo "Creating ./bin/..."; mkdir bin; fi;
	@if [ ! -d ./obj ]; then echo "Cretaing ./obj/..."; mkdir obj; fi;
	@if [ ! -d ./src ]; then echo "Cretaing ./src/..."; mkdir src; fi;

main: main.c
	$(CC) $(CFLAGS) -o $(APP) $(APP).c

clean:
	rm -r ./$(APP)

