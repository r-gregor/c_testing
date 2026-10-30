define tms
	echo -n "[ $$(date +"%Y%m%d_%H%M%S") ] "
endef

define makedir
	@if [ ! -d ./$(1) ];then $(call tms); echo "Creating directory ./$(1)"; mkdir $(1);fi;                                    
endef


TARGET = main

SRCDIR = src
INCDIR = include
BUILDDIR = bin
OBJDIR = obj

SOURCE = $(wildcard $(SRCDIR)/*.c)
OBJNAME = $(SOURCE:.c=.o)
OBJECTS = $(patsubst $(SRCDIR)/%.o,$(OBJDIR)/%.o, $(OBJNAME)) 
 
CC = gcc
CFLAGS = -g -Wall 
RM = rm -v

all: dirs info $(BUILDDIR)/$(TARGET)

dirs:
	@$(call tms)
	@echo "Making missing directories..."
	@$(call makedir,$(BUILDDIR))
	@$(call makedir,$(OBJDIR))
	@$(call tms)
	@echo "--- Done ---"

info:
	@$(call tms)
	@echo "Compiling objects..."


$(BUILDDIR)/$(TARGET): $(OBJECTS)
	@$(call tms)
	@echo "Building final target..."
	@$(call tms)
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCDIR)
	@$(call tms)
	@echo "--- Done ---"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(call tms)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

.PHONY: help run clean

run: $(BUILDDIR)/$(TARGET)
	@$(BUILDDIR)/$(TARGET)

clean:
	$(RM) ./$(OBJDIR)/*.o
	$(RM) ./$(BUILDDIR)/*

rmdirs:
	$(RM) -r ./obj ./build

# test printout before all:
OBJECT = $(notdir $(OBJECTS))
help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECTS)"

	@echo "obj: $(OBJECT)"

