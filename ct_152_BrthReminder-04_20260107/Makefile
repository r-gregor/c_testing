# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./bin/x86_64-w64-mingw32-gcc-11.1.0.exe
CC       := gcc
CFLAGS   := -g -Wall
RM       := rm -v
SRCDIR   := ./src
BUILDDIR := ./build
SRCS     := $(shell find $(SRCDIR) -name *.c)
PROGS    := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%,$(SRCS))

all: newbindir main

newbindir:
	@mkdir -p $(BUILDDIR)
	@cp -vn ROJSTNIDNEVI.txt $(BUILDDIR)

main: $(PROGS)

$(PROGS): $(SRCS)
	@cp -vn ROJSTNIDNEVI.txt $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BUILDDIR)/*

