# makefile for the hpc course
CC      = gcc
OPT     = -g -O3
XLIBS	= -L/usr/lib64/atlas -lsatlas -lm
WARN    = -Wall
CFLAGS  = $(OPT) $(WARN) # the compiler flags


# Source files and derived objects
SRCS_DIR = src
SRCS    = $(wildcard $(SRCS_DIR)/*.c) #SRCS = data.c main.c io.c
OBJECTS = $(SRCS:.c=.o) #OBJECTS = data.o main.o io.o

# Target executable
TARGET  = project1

# define project
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(XLIBS)


clean : 
	@rm -f $(SRCS_DIR)/*.o core

realclean : clean
	@rm -f $(TARGET) Makefile.dep outputs/*

run_test : 
	sh jobs/job.sh

run_program:
	./$(TARGET) 3 4 5 

depend: 
	$(CC) -MM $(SRCS) > Makefile.dep
#$(CC) -MM data.c main.c io.c > Makefile.dep

-include Makefile.dep
