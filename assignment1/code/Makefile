TARGET	= libmatmult.so
LIBSRCS	= $(wildcard src/*.c)
LIBOBJS	= $(LIBSRCS:.c=.o)

INCLUDEPATH = -I../include

OPT     = -g
PIC	= -fPIC

CC      = gcc
CFLAGS  = $(OPT) $(PIC) $(XOPTS) $(INCLUDEPATH)

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
	$(CC) -MM $(LIBSRCS) > Makefile.dep
#$(CC) -MM data.c main.c io.c > Makefile.dep
run_program:
	./$(TARGET)

-include Makefile.dep
