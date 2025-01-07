# Compiler settings
CC      = gcc
OPT     = -g
XOPTS = ""
PIC	= -fPIC
INCLUDEDIR= -Iinclude
CFLAGS  = $(OPT) $(PIC) $(XOPTS) $(INCLUDEDIR)

SRCDIR = src
OBJDIR = build
BINDIR = bin
LIBSRCS	= $(wildcard src/*.c)
LIBOBJS	= $(patsubst src/%.c, $(OBJDIR)/%.o, $(LIBSRCS))



TARGET	= $(BINDIR)/libmatmult.so





SOFLAGS = -shared 
XLIBS	= -L/usr/lib64/atlas -lsatlas

$(TARGET): $(LIBOBJS)
	$(CC) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS)

clean:
	@/bin/rm -f core core.* $(LIBOBJS) 

realclean : clean
	@rm -f $(TARGET) Makefile.dep outputs/*

run_test : 
	sh jobs/job.sh

depend: 
	$(CC) -MM $(INCLUDEDIR) $(LIBSRCS) > Makefile.dep 
#$(CC) -MM data.c main.c io.c > Makefile.dep
run_program:
	./$(TARGET)

-include Makefile.dep
