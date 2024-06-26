# Compiler
CC=gcc

# Compiler flags
CFLAGS=-g --std=c99

# Linker flags
LDFLAGS=-Wl,--wrap=sub -Wl,--wrap=add -Wl,--wrap=simple_calculator_init -Wl,--wrap=simple_calculator_destroy

# Source files
SRCS:=$(wildcard *.c)

# Object files
OBJS=$(SRCS:.c=.o)

# Executable name
EXEC=smart_calculator_test

# Default target
all:$(EXEC)

# Rule to link the object files into the final executable
$(EXEC):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile source files into object files
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up the build files
.PHONY:clean

clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
