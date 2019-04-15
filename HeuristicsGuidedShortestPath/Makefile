.SUFFIXES:

# specify C standard
STD=-std=c11
# specify C compiler
CC=gcc $(STD)
# specify optimization information
OPT=-O3 -march=x86-64 -mtune=generic -pipe
# specify compile flags
CFLAGS=-Wall -Wextra -pedantic $(OPT)
# preprocessor flags (needed for M_PI)
CPPFLAGS=-D_XOPEN_SOURCE=500
# specify link flags
LDFLAGS=-s
# specify libraries
LIBS=-lm

all:	simulate

simulate:	simulate.o helper.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

simulate.o:	simulate.c helper.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

helper.o:	helper.c helper.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) simulate.o helper.o core

distclean:	clean
	$(RM) simulate

.PHONY:	all clean distclean

