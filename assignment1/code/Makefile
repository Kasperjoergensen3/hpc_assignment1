# name tag
TAG = test
# Directories
SRCDIR  = src
OBJDIR  = build
LIBDIR  = lib
DRIVER = drivers/matmult_c.gcc

# Compiler settings
CC      = gcc
OPT     = -g
XOPTS   = 
PIC     = -fPIC
WARN    = -Wall
CFLAGS  = $(OPT) $(PIC) $(XOPTS) $(WARN)

# Source and object files
LIBSRCS = $(wildcard $(SRCDIR)/*.c)
LIBOBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(LIBSRCS))

# Output shared library
TARGET  = $(LIBDIR)/$(TAG)/libmatmult.so

# Shared library flags
SOFLAGS = -shared 
XLIBS   =  -L/usr/lib64/atlas -lsatlas

# Verbosity control
V ?= 1
Q = $(if $(filter 1,$V),,@)

# Ensure output directories exist
$(shell mkdir -p $(OBJDIR) $(LIBDIR) outputs figures data)

# Build the shared library
$(TARGET): clean depend $(LIBOBJS)
	$(Q)$(CC) $(CFLAGS) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	$(Q)rm -f $(LIBOBJS)

realclean: clean
	$(Q)rm -rf $(LIBDIR) $(OBJDIR) Makefile.dep outputs figures data

# Run test script
run_test:
	$(Q)sh jobs/job.sh

# Generate dependencies
depend:
	$(Q)$(CC) -MM $(CFLAGS) $(LIBSRCS) > Makefile.dep

# Run program (assumes an executable, not shared library)
run_program: $(TARGET)
	$(Q)./$(TARGET)

# Run driver with example input
DIMS = 1000 2000 400
ORDER = nat
run_driver:
	$(Q)LD_LIBRARY_PATH=./$(LIBDIR)/$(TAG) ./$(DRIVER) $(ORDER) $(DIMS)

git:
	git add .
	git commit -m "commit"
	git push

# Include dependency file if it exists
-include Makefile.dep
