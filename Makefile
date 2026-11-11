# for win
# CC=/c/Users/gregor.redelonghi/majstaf/majprogs/mingw./bin/x86_64-w64-mingw32-gcc-11.1.0.exe
CC       := gcc
CFLAGS   := -g -Wall
RM       := rm -v
SRCDIR   := ./src
BUILDDIR := ./build
SRCS     := $(wildcard $(SRCDIR)/*.c)
PROGS    := $(SRCS:$(SRCDIR)/%.c=%)

all: newbindir $(PROGS)

newbindir:
	@mkdir -p $(BUILDDIR)
	@cp -vn ROJSTNIDNEVI.txt $(BUILDDIR)

%: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$@ $<


clean:
	$(RM) $(BUILDDIR)/*

