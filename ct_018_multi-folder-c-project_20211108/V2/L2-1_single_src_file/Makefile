define tms
	echo -n "[ $$(date +"%Y%m%d_%H%M%S") ] "
endef

define makedir
	@if [ ! -d ./$(1) ];then $(call tms); echo "Creating directory ./$(1)/..."; mkdir $(1);fi;                                    
endef

CC=gcc
CFLAGS= -g -Wall
APP=main
BIN=bin
OBJ=obj
SRC=src

all: dirs main

dirs:
	@$(call makedir,$(BIN))
	@$(call makedir,$(OBJ))
	@$(call makedir,$(SRC))

main: bin/$(APP)

bin/$(APP): obj/$(APP).o
	@$(call tms)
	@echo "Creating final executable..."
	@$(call tms)
	$(CC) $(CFLAGS) -o $@ $^
	@$(call tms)
	@echo "--- Done ---"

obj/$(APP).o: src/$(APP).c
	@$(call tms)
	@echo "Creating object files..."
	@$(call tms)
	$(CC) -c -o $@ $^
	@$(call tms)
	@echo "--- Done ---"

clean:
	@$(call tms)
	@echo "Removing executables and objects..."
	@$(call tms)
	rm -r ./$(BIN) ./$(OBJ)


run:
	@$(cal tms)
	@echo "Runing $(APP)..."
	@./bin/$(APP)

