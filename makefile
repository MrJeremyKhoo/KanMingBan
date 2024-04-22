# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g

# Source files
SRCS = Application/dataParser.c Application/errorHandler.c Application/kmbInit.c Application/headerParser.c main.c Presentation/table.c Business/commandParser.c Application/add.c Application/delete.c Application/promote.c Application/regress.c Application/availID.c

# Header files
HDRS = Application/dataParser.h Application/errorHandler.h Application/kmbInit.h Presentation/table.h Business/commandParser.h ApplicationheaderParser.h Application/add.h Application/delete.h Application/promote.h Application/regress.h Application/availID.h

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
