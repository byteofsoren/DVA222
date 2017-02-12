## My generic makefile written by Magnus Sörensen. GPL3.0 Lisense.

## CROSS_TOLL is used if you need co add a cross platform compiler.
CROSS_TOLL=
## CC is the compiler you use in this project.
CC=$(CROSS_TOLL) g++
TTY=/dev/pts/2
## Target is the source files with out .c or .cpp  tex main.c ~> main
CTARGET=input rand
CPPTARGET=main game
COBJECTS=$(CTARGET:=.o)
CPPOBJECTS=$(CPPTARGETS:=.0)
## EXECFILE is the name on the exe file you want
EXECFILE=prog
## LFLAGS is the libary linker flags like -lncurses or -lpthread.
CLFLAGS=-pthread -lrt
CPPFLAGS=
#LFLAGS=-lncurses -lm
## CFLAGS tells the copmiler to compile with diffrent flaggs mostly -g -Wall
CFLAGS=-g -Wall
CPPFLAGS=-g -Wall
## If files is from windows then run
## recode ISO-8859-1..UTF-8 main.c
## or even better for file in *.{c,h} ; do recode ISO-8859-1..UTF-8 $file; done
## Also remember to create ctags in your src dir
##  $ ctags -R

$(CTARGET):
	$(CC) $(CFLAGS) $(CLFLAGS) -c $@.c

$(CPPTARGET):
	$(CC) $(CPPFLAGS) $(CPPOBJECTS) -c $@.cpp

all: clean $(CTARGET) $(CPPTARGET)
	$(CC) $(CFLAGS) $(CLFLAGS) $(CPPFLAGS)  $(COBJECTS) $(CPPOBJECTS) -o $(EXECFILE)

run: clean all
	./$(EXECFILE)

debug: clean all
	cgdb ./$(EXECFILE)

ddd: clean all
	ddd ./$(EXECFILE) &

.PHONY: clean valgrind

valgrind: clean all
	valgrind ./$(EXECFILE)

clean:
	rm -f *.o $(EXECFILE) *.gch
