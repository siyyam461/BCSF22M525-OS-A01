# src/Makefile - builds objects from .c files in src/
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../include -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
OBJDIR = ../obj

.PHONY: all clean

all: $(OBJS)
	@echo "src: built objects: $(OBJS)"

%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	@echo "src: cleaning objects"
	-rm -f $(OBJDIR)/*.o
