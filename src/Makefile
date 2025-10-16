# src/Makefile - builds objects from .c files in src/
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../include -g
SRCS = $(wildcard *.c)
# objs are placed in ../obj with same basename
OBJDIR = ../obj
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(OBJS)
	@echo "src: built objects: $(OBJS)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "src: cleaning objects"
	-rm -f $(OBJDIR)/*.o
