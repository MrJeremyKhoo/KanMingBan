# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = inputParser.c main.c table.c

# Header files
HDRS = inputParser.h table.h

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = my_program

# Default target
all: $(EXEC)

# Rule for building the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule for generating object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)

