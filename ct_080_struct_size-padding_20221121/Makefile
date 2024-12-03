# from:	More Tips for Setting up a Programming Project: Subdirectories and Structure
# 		https://www.youtube.com/watch?v=CRlqU9XzVr4
# 		Jacob Sorber
# 		2022-11-16

# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw6/bin/x86_64-w64-mingw32-gcc-11.1.0.exe
CC=gcc
CFLAGS=-g -Wall
SRCDIR=src
OBJDIR=obj
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BUILDDIR=bin
BUILD=$(BUILDDIR)/struct_padding
RM=/us./build/rm

# all: $(BUILD) test
all: $(BUILD)

# release: CFLAGS=-Wall -O2 -DNDEBUG
# release: clean
# release: $(BUILD)

$(BUILD): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(BUILD)
	$(BUILD)	

clean:
	$(RM) -r $(BUILDDIR)/* $(OBJDIR)/*

.PHONY setup:
	mkdir -p ./{$(SRCDIR),$(OBJDIR),$(BUILDDIR)}

