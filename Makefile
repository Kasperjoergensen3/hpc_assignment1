# makefile for the hpc course
CC      = gcc
OPT     = -g -O3
WARN    = -Wall
CFLAGS  = $(OPT) $(WARN) # the compiler flags

# Source files and derived objects
SRCS_DIR = src
SRCS    = $(wildcard $(SRCS_DIR)/*.c) #SRCS = data.c main.c io.c
OBJECTS = $(SRCS:.c=.o) #OBJECTS = data.o main.o io.o

# Target executable
TARGET  = excer1

# define project
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)


# explicit rules for compiling .o files (only necessary if using make -r wich disables the implicit rules (not recommended))
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
# end of explicit rules

clean : 
	@rm -f $(SRCS_DIR)/*.o compiler

realclean : clean
	@rm -f $(TARGET) Makefile.dep outputs/*

run_test : 
	sh jobs/job.sh

depend: 
	$(CC) -MM $(SRCS) > Makefile.dep
#$(CC) -MM data.c main.c io.c > Makefile.dep

-include Makefile.dep
