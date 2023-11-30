define tms
	echo -n "[ $$(date +"%Y%m%d_%H%M%S") ] "
endef

CC = gcc
CFLAGS = -g -Wall
RM = rm -v
TARGET = main

all: main

main: main.o myfunc.o
	@$(call tms)
	@echo "Building $(TARGET)..."
	@$(call tms)
	$(CC) $(CFLAGS) -o $@ $^
	@$(call tms)
	@echo "--- Done ---"

%.o: %.c
	@$(call tms)
	$(CC) -c $^

clean:
	@$(call tms)
	@echo "Removing *.o an *.exe files..."
	@$(RM) *.o $(TARGET)
	@$(call tms)
	@echo "--- Done ---"

run:
	@$(call tms)
	@echo "Running $(TARGET)..."
	@./$(TARGET)


