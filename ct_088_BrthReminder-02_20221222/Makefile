# from:	More Tips for Setting up a Programming Project: Subdirectories and Structure
# 		https://www.youtube.com/watch?v=CRlqU9XzVr4
# 		Jacob Sorber
# 		2022-11-16

# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw64/bin/x86_64-w64-mingw32-gcc-11.1.0.exe
CC=gcc
CFLAGS=-g -Wall
SRCDIR=src
OBJDIR=obj
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/BrthReminder
RM=/usr/bin/rm

# all: $(BIN) test
all: $(BIN)

# release: CFLAGS=-Wall -O2 -DNDEBUG
# release: clean
# release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(BIN)
	$(BIN)	

clean:
	$(RM) -r $(BINDIR)/* $(OBJDIR)/*

.PHONY setup:
	mkdir -p ./{$(SRCDIR),$(OBJDIR),$(BINDIR)}

