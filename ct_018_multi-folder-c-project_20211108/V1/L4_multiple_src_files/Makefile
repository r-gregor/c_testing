TARGET = main

SRCDIR = src
INCDIR = inc
BINDIR = bin
OBJDIR = obj

SOURCE = $(wildcard $(SRCDIR)/*.c)
OBJNAME = $(SOURCE:.c=.o)
OBJECTS = $(patsubst $(SRCDIR)/%.o,$(OBJDIR)/%.o, $(OBJNAME)) 
 
CC = gcc
CFLAGS = -g -Wall 
RM = rm -v

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

.PHONY: help run clean

run: $(BINDIR)/$(TARGET)
	@$(BINDIR)/$(TARGET)

clean:
	$(RM) ./$(OBJDIR)/*.o
	$(RM) ./$(BINDIR)/*


# test printout before all:
OBJECT = $(notdir $(OBJECTS))
help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECTS)"
	@echo "obj: $(OBJECT)"

