# Directories
SRCDIR  = src
OBJDIR  = build
DRIVERDIR = drivers
BINDIR  = bin
INCLUDEDIR = include

# Compiler settings
CC      = gcc
OPT     = -g
XOPTS   = 
PIC     = -fPIC
WARN    = -Wall
CFLAGS  = $(OPT) $(PIC) $(XOPTS) -I$(INCLUDEDIR) $(WARN)

# Source and object files
LIBSRCS = $(wildcard $(SRCDIR)/*.c)
LIBOBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(LIBSRCS))

# Output shared library
TARGET  = $(BINDIR)/libmatmult.so

# Shared library flags
SOFLAGS = -shared 
XLIBS   =  #-L/usr/lib64/atlas -lsatlas

# Additional driver sources
DRIVERSRC = $(DRIVERDIR)/matmult_c.gcc
DRIVEROBJ = $(OBJDIR)/matmult_c.o
DRIVERBIN = $(BINDIR)/matmult_c

# Verbosity control
V ?= 1
Q = $(if $(filter 1,$V),,@)

# Ensure output directories exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Build the shared library
$(TARGET): $(LIBOBJS)
	@echo "Linking $@..."
	$(Q)$(CC) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

# Compile the driver
$(DRIVEROBJ): $(DRIVERSRC)
	@echo "Compiling driver $<..."
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

# Link the driver with the shared library
$(DRIVERBIN): $(DRIVEROBJ) $(TARGET)
	@echo "Linking driver..."
	$(Q)$(CC) -o $@ $(DRIVEROBJ) -L$(BINDIR) -lmatmult $(XLIBS)

# Clean build artifacts
clean:
	@echo "Cleaning object files..."
	$(Q)rm -f $(LIBOBJS)

realclean: clean
	@echo "Removing binary and dependency files..."
	$(Q)rm -rf $(BINDIR) $(OBJDIR) Makefile.dep outputs/*

# Run test script
run_test:
	@echo "Running test script..."
	$(Q)sh jobs/job.sh

# Generate dependencies
depend:
	@echo "Generating dependencies..."
	$(Q)$(CC) -MM $(CFLAGS) $(LIBSRCS) > Makefile.dep

# Run program (assumes an executable, not shared library)
run_program: $(TARGET)
	@echo "Executing binary..."
	$(Q)./$(TARGET)

# Include dependency file if it exists
-include Makefile.dep
