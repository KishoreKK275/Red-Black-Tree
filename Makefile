#==============================================================================
# Makefile for Red-Black Tree project
#==============================================================================
CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=c99
TARGET  = red_black_tree
SRCS    = main.c rbt_utils.c rotate.c insert.c display.c search.c findmin.c findmax.c delete.c deletemin.c deletemax.c
OBJS    = $(SRCS:.c=.o)
#------------------------------------------------------------------------------
# Default target
#------------------------------------------------------------------------------
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Build successful  →  ./$(TARGET)"
#------------------------------------------------------------------------------
# Compile each .c to .o
#------------------------------------------------------------------------------
%.o: %.c rbt.h$(CC) $(CFLAGS) -c -o $@ $<
#------------------------------------------------------------------------------
# Convenience targets
#------------------------------------------------------------------------------
run: $(TARGET)	
	./$(TARGET)
clean:	
	rm -f $(OBJS) $(TARGET)
.PHONY: all run clean

#$(TARGET): $(OBJS); $(CC) $(CFLAGS) -o $@ $^
#%.o: %.c rbt.h; $(CC) $(CFLAGS) -c $< -o $@
#run: all; ./$(TARGET)