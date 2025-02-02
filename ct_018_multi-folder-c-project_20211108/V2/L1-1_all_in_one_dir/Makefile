define tms
	@echo -n "[ $$(date +"%Y%m%d_%H%M%S") ] -- "
endef

CC=gcc
CFLAGS= -g -Wall
APP=main

all: dirs main

dirs:
	$(call tms)
	@echo "Directories src, obj, bin: not yet needed in L1, so not created."
# 	@if [ ! -d ./bin ]; then echo "Creating ./bin/..."; mkdir bin; fi;
# 	@if [ ! -d ./obj ]; then echo "Cretaing ./obj/..."; mkdir obj; fi;
# 	@if [ ! -d ./src ]; then echo "Cretaing ./src/..."; mkdir src; fi;

main: main.c
	$(call tms)
	@echo "Creating executable $(APP) ..."
	$(CC) $(CFLAGS) -o $(APP) $(APP).c

clean:
	$(call tms)
	@echo "Removing executable ..."
	rm -r ./$(APP)

