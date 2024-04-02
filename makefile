# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = Application/dataParser.c Application/errorHandler.c Application/kmbInit.c main.c Presentation/table.c

# Header files
HDRS = Application/dataParser.h Application/errorHandler.h Application/kmbInit.h Presentation/table.h

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = a

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

check:
