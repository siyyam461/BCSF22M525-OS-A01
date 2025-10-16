# src/Makefile - builds objects from .c files in src/
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../include -g
PICFLAGS = -fPIC
SRCS = $(wildcard *.c)
OBJDIR = ../obj
# build both normal objects and PIC versions for shared lib when needed
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
PIC_OBJS = $(patsubst %.c,$(OBJDIR)/%.pic.o,$(SRCS))

.PHONY: all clean

all: $(OBJS) $(PIC_OBJS)
	@echo "src: built objects: $(OBJS) and PIC objects: $(PIC_OBJS)"

# normal object
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# PIC object for shared library
$(OBJDIR)/%.pic.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(PICFLAGS) -c $< -o $@

clean:
	@echo "src: cleaning objects"
	-rm -f $(OBJDIR)/*.o $(OBJDIR)/*.pic.o
